CMAKE ?= cmake
BUILD_DIR ?= build
NO_GUI_BUILD_DIR ?= $(BUILD_DIR)-no-gui
BUILD_TYPE ?= Release

.PHONY: all configure build build-gui build-no-gui clean rebuild

all: build-gui

configure:
	$(CMAKE) -S . -B "$(BUILD_DIR)" \
		-DCMAKE_BUILD_TYPE="$(BUILD_TYPE)" \
		-DSUDOKU_BUILD_GUI=ON

build: build-gui

build-gui: configure
	$(CMAKE) --build "$(BUILD_DIR)" --parallel

build-no-gui:
	$(CMAKE) -S . -B "$(NO_GUI_BUILD_DIR)" \
		-DCMAKE_BUILD_TYPE="$(BUILD_TYPE)" \
		-DSUDOKU_BUILD_GUI=OFF
	$(CMAKE) --build "$(NO_GUI_BUILD_DIR)" --parallel

clean:
	rm -rf "$(BUILD_DIR)" "$(NO_GUI_BUILD_DIR)"

rebuild: clean
	$(MAKE) build-gui
