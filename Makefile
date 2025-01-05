# Compiler
CC = gcc
CFLAGS = -Wall -g -I../include

# Source files
SOURCES = src/main.c src/userInteraction.c src/repl.c src/btree.c src/db.c
TARGET = bin/pacificStandard

# Default Target
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o bin/pacificStandard $(SOURCES)

# Run the program
run: $(TARGET)
	./$<

# Clean up
clean:
	rm -f $(TARGET)
