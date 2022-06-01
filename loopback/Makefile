##! Makefile for Loopback application on Linux/UNIX
##! @file Makefile
##! @brief Loopback application on Linux/UNIX for HAW-Hamburg
##! @author Andreas Baulig <andreas.baulig@haw-hamburg.de>
##! @note (C) 2022
##!
##! Defined build targets for compiling the loopback application on Linux/UNIX.
##! Application binaries are saved to the `bin/` directory.
##!
##! Targets:
##! * `make` or `make all` - compile executable application binary
##! * `make clean` - delete all generated files
##! * `make doxygen` - generate doxygen documentation
##!
##! @cond
# ^ for Doxygen to ignore the Makefile rules

CC?=gcc
RMDIR?=rm -rf
MKDIR?=mkdir -p
CFLAGS?=-O2 -Wall
DEPFLAGS?=-MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d
LDFLAGS?=-ldl

SRC_DIR:=src
BUILD_DIR:=build
BIN_DIR:=bin
DOC_DIR:=doxygen

EXEC:=loopback_starter
LIBS:=-lm
SOURCES:=$(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJECTS:=$(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
INCLUDES:=\
	-I include
DEPFILES:=$(SOURCES:$(SRC_DIR)%.c=$(BUILD_DIR)/%.d)

NODEPS:=clean

.PHONY: all clean doxygen

all: $(EXEC)

$(EXEC): $(OBJECTS) $(LIBS)
	@$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $(OBJECTS) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c -o $@ $<

clean_all: clean clean_gen

clean:
	$(RMDIR) $(BIN_DIR) $(BUILD_DIR) $(DOC_DIR)

clean_gen:
	$(RMDIR) $(SRC_DIR)/gen

doxygen:
	doxygen doxygen.conf

# Don't create dependencies when we're cleaning, for instance
ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
# Chances are, these files don't exist. That's why we do -include instead of
# include.
-include $(DEPFILES)
endif

##! @endcond
# ^ for Doxygen to ignore the Makefile rules
