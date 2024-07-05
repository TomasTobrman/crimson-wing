# =========================================================================== #
#  General Makefile for an Executable                                         #
# =========================================================================== #

# ==== Directories ========================================================== #
BINARY_FOLDER   := ./bin
OBJECT_FOLDER   := ./obj
SOURCE_FOLDER   := ./$(PROJECT)/src
DIRECTORIES     := $(shell find $(PROJECT) -type d)

# ==== Files ================================================================ #
SOURCE_FILES    := $(shell find $(PROJECT) -name *.c)
OBJECT_FILES    := $(SOURCE_FILES:%=$(OBJECT_FOLDER)/%.o)

# ==== Flags ================================================================ #
DEFINES         := -DCWIMPORT
COMPILER_FLAGS  := -Wall -Werror
LINKER_FLAGS    := -L$(BINARY_FOLDER) $(ADDL_LINK_FLAGS)
INCLUDE_FLAGS   := -I$(SOURCE_FOLDER) $(ADDL_INC_FLAGS)

ifeq ($(OS),Windows_NT)
	$(error Windows is not supported)
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		BUILD_PLATFORM := linux
		EXTENSION      := 
		COMPILER_FLAGS += 
	endif
	ifeq ($(UNAME_S),Darwin)
		BUILD_PLATFORM := macos
		EXTENSION      := 
		COMPILER_FLAGS += -fvisibility=hidden -fpic -fdeclspec
	endif
endif

# ==== Debug ================================================================ #
DEFINES         += -D_DEBUG
COMPILER_FLAGS  += -g -MD -O0
LINKER_FLAGS    += -g

# ==== Targets ============================================================== #
CC := clang

.PHONY: all
all: scaffold compile link gen_compile_flags

.PHONY: scaffold
scaffold:
	@mkdir -p $(BINARY_FOLDER)
	@mkdir -p $(addprefix $(OBJECT_FOLDER)/,$(DIRECTORIES))

.PHONY: link
link: scaffold $(OBJECT_FILES)
	@echo linking "$(PROJECT)"...
	@$(CC) $(OBJECT_FILES) $(LINKER_FLAGS) -o $(BINARY_FOLDER)/$(PROJECT)$(EXTENSION)

.PHONY: compile
compile:
	@echo --- Building "$(PROJECT)" Executable ---
-include $(OBJECT_FILES:.o=.d)

.PHONY: clean
clean:
	@echo --- Cleaning "$(PROJECT)" ---
	@rm -rf $(BINARY_FOLDER)/$(PROJECT)$(EXTENSION)
	@rm -rf $(OBJECT_FOLDER)/$(PROJECT)

$(OBJECT_FOLDER)/%.c.o: %.c
	@echo "  "$<...
	@$(CC) $< $(COMPILER_FLAGS) $(INCLUDE_FLAGS) $(DEFINES) -c -o $@

-include $(OBJECT_FILES:.o=.d)

.PHONY: gen_compile_flags
gen_compile_flags:
	@echo $(INCLUDE_FLAGS) $(DEFINES) | tr " " "\n" | sed "s/\-I\.\//\-I\.\.\//g" > $(PROJECT)/compile_flags.txt

# =========================================================================== #
