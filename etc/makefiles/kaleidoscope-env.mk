mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

export KALEIDOSCOPE_DIR ?= $(abspath $(mkfile_dir)/../..)
export KALEIDOSCOPE_BIN_DIR ?= $(KALEIDOSCOPE_DIR)/bin
export KALEIDOSCOPE_ETC_DIR ?= $(KALEIDOSCOPE_DIR)/etc

export ARDUINO_CONTENT ?= $(KALEIDOSCOPE_DIR)/.arduino
export ARDUINO_DIRECTORIES_DATA ?= $(ARDUINO_CONTENT)/data
export ARDUINO_DIRECTORIES_DOWNLOADS ?= $(ARDUINO_CONTENT)/downloads
export ARDUINO_DIRECTORIES_USER ?= $(ARDUINO_CONTENT)/user
export ARDUINO_CLI_CONFIG ?= $(ARDUINO_DIRECTORIES_DATA)/arduino-cli.yaml
export ARDUINO_BOARD_MANAGER_ADDITIONAL_URLS ?= https://raw.githubusercontent.com/keyboardio/boardsmanager/master/package_keyboardio_index.json

ifneq ($(VERBOSE),)
export ARDUINO_VERBOSE ?= --verbose
else
export ARDUINO_VERBOSE ?=
endif
