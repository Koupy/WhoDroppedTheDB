# Compiler
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = src/main.c src/userInteraction.c src/repl.c src/btree.c
TARGET = bin/pacificStandard

# Default Target
all:
	$(CC) $(CFLAGS) -o bin/pacificStandard $(SOURCES)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	rm -f main
