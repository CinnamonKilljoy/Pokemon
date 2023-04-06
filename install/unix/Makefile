LIBRARY_PATH = /usr/lib
INCLUDE_PATH = /usr/include

CXX = /usr/bin/g++

APP             = pokemon-text
BUILD_DIR       = $(ROOT_DIR)/build
INCLUDES        = $(shell find $(SRC_DIR) -type d)

OBJS            = $(shell find $(SRC_DIR) -name "*.cpp")
ROOT_DIR        = ../..
RUN_DIR         = $(ROOT_DIR)/run
SRC_DIR         = $(ROOT_DIR)/src

CONSTANTS += $(addprefix -D, $(APP_FLAGS))

####   Libraries.   ####

LIBRARY_DIRECTORIES     =
LIBRARIES               = jsoncpp stdc++fs
HEADERS                 = jsoncpp/include

CFLAGS += $(addprefix -I, $(INCLUDES))
CFLAGS += $(addprefix -I$(INCLUDE_PATH)/, $(HEADERS))
LDLIBS += $(addprefix -l, $(LIBRARIES))

####   Constants for the application.  ####

APP_FLAGS   += APP_NAME=$(APP)

####   Compiler flags.   ####

CFLAGS  +=  -pedantic \
            -O2 \
            -W \
            -Wall \
            -Wdisabled-optimization \
            -Werror \
            -Wfloat-equal \
            -Wformat=2 \
            -Wpedantic \
            -Wpointer-arith \

CPPFLAGS += -std=c++17 \
            -O2 \
            -pedantic-errors \
            -Wall \
            -Wcast-align \
            -Wconversion \
            -Werror \
            -Wextra \
            -Wno-long-long \
            -Wno-psabi \
            -Wno-variadic-macros \
            -Woverloaded-virtual \
            -Wsign-promo \
            -Wunreachable-code

.PHONY: clean

all: $(APP)

$(APP): $(OBJS)
	$(info Unix build.)
	$(info $(OBJS))
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(RUN_DIR)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CONSTANTS) $^ -o $(BUILD_DIR)/$@ $(LDLIBS)
	@cp -r $(BUILD_DIR)/** $(RUN_DIR)

clean:
	$(info Cleaning tests.)
	@$(RM) -rf $(BUILD_DIR)
