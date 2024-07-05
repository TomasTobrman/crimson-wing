# =========================================================================== #
#  Main Makefile                                                              #
# =========================================================================== #

# ==== Variables ============================================================ #
ACTION ?= all
LIB_MAKE := lib.makefile
EXE_MAKE := exe.makefile

# ==== Main Targets ========================================================= #
.PHONY: all
all:
	@ $(MAKE) -s -f $(LIB_MAKE) $(ACTION) PROJECT=garrulus
	@ $(MAKE) -s -f $(EXE_MAKE) $(ACTION) PROJECT=sandbox ADDL_INC_FLAGS="-I./garrulus/include" ADDL_LINK_FLAGS="-lgarrulus"

.PHONY: run
run:
	@ LD_LIBRARY_PATH=~/Morrigan/crimson-wing/bin ./bin/sandbox

# ==== Other Targets ======================================================== #
.PHONY: scaffold
scaffold: ACTION = scaffold
scaffold: all

.PHONY: clean
clean: ACTION = clean
clean: all

.PHONY: gen_compile_flags
gen_compile_flags: ACTION = gen_compile_flags
gen_compile_flags: all

# =========================================================================== #
