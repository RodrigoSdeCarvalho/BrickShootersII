# Makefile Definitions
include makedefs

# Name of the project
PROJ_NAME = Main

# Paths to other makefiles
CONCURRENCY_MAKEFILE := $(SRC)/Concurrency/makefile
GAME_CONTROL_MAKEFILE := $(SRC)/Game/Control/makefile
GAME_INTERFACE_MAKEFILE := $(SRC)/Game/Interface/makefile
GAME_LOGIC_MAKEFILE := $(SRC)/Game/Logic/makefile
DEBUG_MAKEFILE := $(SRC)/Debug/makefile
UTILS_MAKEFILE := $(SRC)/Utils/makefile
TEST_MAKEFILE := $(SRC)/Test/makefile
MAIN_MAKEFILE := $(SRC)/makefile

# Compiler and linker
CC = g++

# Command used at clean target
RM = rm -rf

# Default target
all: build

# Object files
OBJ = $(OBJDIR)/main.o $(wildcard $(OBJDIR)/*.o)

# Creates Main executable
$(PROJ_NAME): $(OBJ)
	@echo 'Building binary using GCC linker: $@'
	$(CC) $^ $(LIBS) -o $@
	@echo 'Finished building binary: $@'
	@echo ' '

build: compileSource
	@$(MAKE) -s $(PROJ_NAME)

compileSource:
	@mkdir -p $(OBJDIR)
	@$(MAKE) -s -C $(SRC)/Game/Control -f $(GAME_CONTROL_MAKEFILE)
	@$(MAKE) -s -C $(SRC)/Game/Interface -f $(GAME_INTERFACE_MAKEFILE)
	@$(MAKE) -s -C $(SRC)/Game/Logic -f $(GAME_LOGIC_MAKEFILE)
	@$(MAKE) -s -C $(SRC)/Concurrency -f $(CONCURRENCY_MAKEFILE)
	@$(MAKE) -s -C $(SRC)/Utils -f $(UTILS_MAKEFILE)
	@$(MAKE) -s -C $(SRC)/Debug -f $(DEBUG_MAKEFILE)
	@$(MAKE) -s -C $(SRC)/Test -f $(TEST_MAKEFILE)
	@$(MAKE) -s -C $(SRC) -f $(MAIN_MAKEFILE)

clean:
	rm -rf log.txt
	clear
	@rm -rf $(PROJ_NAME) $(OBJDIR) *~
	echo "Done!"

install:
	sudo apt-get install libsfml-dev
	sudo apt install libpng-dev	

run:
	@if [ "$(log)" = "true" ]; then \
		./$(PROJ_NAME) > log.txt; \
	else \
		./$(PROJ_NAME) ; \
	fi

.PHONY: all clean