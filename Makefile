CMAKE ?= cmake
BUILD_DIR ?= build
BUILD_TYPE ?= Release
RAVEN_PREFIX ?= $(abspath $(CURDIR)/../Raven/install)

.PHONY: all configure build clean rebuild

all: build

configure:
	$(CMAKE) -S . -B "$(BUILD_DIR)" \
		-DCMAKE_BUILD_TYPE="$(BUILD_TYPE)" \
		-DCMAKE_PREFIX_PATH="$(RAVEN_PREFIX)"

build: configure
	$(CMAKE) --build "$(BUILD_DIR)" --parallel

clean:
	rm -rf "$(BUILD_DIR)"

rebuild: clean
	$(MAKE) build
