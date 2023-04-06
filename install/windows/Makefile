CXX = g++

APP             =  pokemon-text
BUILD_DIR       =  $(ROOT_DIR)/build
LIB_DIR         =  $(ROOT_DIR)/lib
INCLUDES        =  $(shell find $(SRC_DIR) -type d)
OBJS            =  $(shell find $(SRC_DIR) -name "*.cpp")
ROOT_DIR        =  $(abspath ../..)
SRC_DIR         =  $(ROOT_DIR)/src

PKGS        = jsoncpp/dist
LIBRARIES   = $(addprefix $(INCLUDE_PATH)/, $(PKGS))
DIRS        = $(shell find $(LIBRARIES) -type d)
OBJS       += $(shell find $(LIBRARIES) -name "*.cpp")
CFLAGS     += $(addprefix -I, $(DIRS) $(INCLUDES))

####   Constants for the application.  ####

APP_FLAGS   += APP_NAME=$(APP)
CONSTANTS += $(addprefix -D, $(APP_FLAGS))

####   Compiler flags.   ####

CPPFLAGS += -std=c++17 \
            -O2 \
            -pedantic-errors \
            -W \
            -Wall \
            -Wcast-align \
            -Wconversion \
            -Wdisabled-optimization \
            -Werror \
            -Wextra \
            -Wformat=2 \
            -Winline \
            -Woverloaded-virtual \
            -Wpedantic \
            -Wpointer-arith \
            -Wsign-promo \
            -Wunreachable-code \
            -Wno-long-long \
            -Wno-psabi \
            -Wno-variadic-macros \

.PHONY: all clean test

all: $(APP)

$(APP): $(OBJS)
	$(info Windows build.)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(LDLIBS) $(CFLAGS) $(CPPFLAGS) $^ $(CONSTANTS) -o $(BUILD_DIR)/$@
	@cp $(BUILD_DIR)/$(APP) $(ROOT_DIR)/run

clean:
	$(info Cleaning tests.)
	@$(RM) -rf $(BUILD_DIR)

test:
	$(info Tests not implemented yet...)
