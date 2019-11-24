# For Linux
# If on Windows: 
# - Run the Visual Studio Command prompt
# - Change to the directory with this 'makefile'
# - Run `nmake -f Makefile.win`
# See https://cognitivewaves.wordpress.com/makefiles-windows/ for more info

OBJ_NAME = gameoflife
BIN_PATH ?= ./bin/
CC = g++
CFLAGS = -g -Wall -std=c++17

OBJS = ./src/*.cpp
INCLUDE = -lSDL2

all : $(OBJS)
	@mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(BIN_PATH)$(OBJ_NAME)
	@echo "$(OBJ_NAME) created at $(BIN_PATH)"

clean :
	rm -fv ./bin/

rebuild :
	$(MAKE) clean
	$(MAKE) all
