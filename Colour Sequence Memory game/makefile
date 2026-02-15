# Compiler
CC = gcc

# Directories
SRC_DIR = src
BIN = game.exe

# Flags
CFLAGS = -Iinclude
LIBS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm

# Build rule
all:
	$(CC) $(SRC_DIR)/*.c -o $(BIN) $(CFLAGS) $(LIBS)

clean:
	del $(BIN)
	del $(SRC_DIR)\*.o
