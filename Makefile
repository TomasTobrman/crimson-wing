# =========================================================================== #
#  Main Makefile                                                              #
# =========================================================================== #

# ==== Variables ============================================================ #
ACTION ?= all
TARGET ?= debug

LIB_MAKE := lib.makefile
EXE_MAKE := exe.makefile

# ==== Main Targets ========================================================= #
.PHONY: all
all:
	@ $(MAKE) -s -f $(LIB_MAKE) $(ACTION) TARGET=$(TARGET) PROJECT=garrulus ADDL_LINK_FLAGS="-lX11"
	@ $(MAKE) -s -f $(EXE_MAKE) $(ACTION) TARGET=$(TARGET) PROJECT=sandbox ADDL_INC_FLAGS="-I./garrulus/include" ADDL_LINK_FLAGS="-lgarrulus -lX11"

.PHONY: run
run:
	@ LD_LIBRARY_PATH=~/Morrigan/crimson-wing/bin ./bin/sandbox

# ==== Other Targets ======================================================== #
.PHONY: scaffold
scaffold: ACTION=scaffold
scaffold: all

.PHONY: clean
clean: ACTION=clean
clean: all

.PHONY: gen_compile_flags
gen_compile_flags: ACTION=gen_compile_flags
gen_compile_flags: all

.PHONY: release
release: TARGET=release
release: all

# =========================================================================== #
