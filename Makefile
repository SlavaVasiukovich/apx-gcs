# TOP_DIR := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

BUILD_DIR := $(if $(BUILD_DIR),$(BUILD_DIR),build)

CMAKE := cmake

all: package

configure:
	@$(CMAKE) -DCMAKE_BUILD_TYPE=Release -H. -B$(BUILD_DIR) -G Ninja

build:
	@$(CMAKE) --build $(BUILD_DIR)

bundle: configure
	$(CMAKE) --build $(BUILD_DIR) --target bundle

release-package: configure
	$(CMAKE) --build $(BUILD_DIR) --target deploy_package



install-tools-osx:
	@brew install ccache clang-format cquery cmake ninja

install-tools-python:
	@pip install networkx simplejson jinja2 pyyaml

install-appimageupdate-linux:
	@sudo rm -rf /usr/src/AppImageUpdate
	@sudo git clone --depth=1 --recurse-submodules https://github.com/AppImage/AppImageUpdate.git /usr/src/AppImageUpdate
	@cd /usr/src/AppImageUpdate && sudo cmake -H. -Bbuild && sudo cmake --build build --target install

# update materialdesignicons
# https://github.com/Templarian/MaterialDesign-Webfont
ICONS_PATH := $(CURDIR)/resources/icons/material-icons
ICONS_BUILD_DIR := $(BUILD_DIR)/icons

update-icons:
	@echo "Updating icons..."
	@mkdir -p $(ICONS_BUILD_DIR)
	@cd $(ICONS_BUILD_DIR); \
		curl -L https://codeload.github.com/Templarian/MaterialDesign-Webfont/zip/master --output icons.zip; \
		rm -fR MaterialDesign-Webfont-master;\
		unzip icons.zip
	@cp -f $(ICONS_BUILD_DIR)/MaterialDesign-Webfont-master/fonts/materialdesignicons-webfont.ttf $(ICONS_PATH).ttf
	@python tools/make_icons.py --src=$(ICONS_BUILD_DIR)/MaterialDesign-Webfont-master/css/materialdesignicons.css --dest=$(ICONS_PATH).json



.PHONY: update-icons build package configure
