# directories
BIN_DIR = bin
BINARY = binary
SRC_DIR = src
LIB_DIR = lib

# Source code file extension
SRCEXT = cpp

# Defines the Compiler
CC = g++

# Dependency libraries
LIBS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 

# %.o file names
NAMES = $(notdir $(basename $(wildcard $(SRC_DIR)/*.$(SRCEXT))))
OBJECTS =$(patsubst %,$(LIB_DIR)/%.o,$(NAMES))

#
# COMPILATION RULES
#

default: all

# Rule for link and generate the binary file
all: $(OBJECTS) 
	@echo -en "LD ";
	$(CC) -o $(BIN_DIR)/$(BINARY) $+ $(DEBUG) $(CFLAGS) $(LIBS)
	@echo -en "\n--\nBinary file placed at" \
			  "$(BIN_DIR)/$(BINARY)\n";


# Rule for object binaries compilation
$(LIB_DIR)/%.o: $(SRC_DIR)/%.$(SRCEXT)
	@echo -en "CC ";
	$(CC) -c $^ -o $@ $(DEBUG) $(CFLAGS) $(LIBS)

# Run
FILES = $(filter-out $@,$(MAKECMDGOALS))
run:
	$(BIN_DIR)/$(BINARY) $(FILES)
