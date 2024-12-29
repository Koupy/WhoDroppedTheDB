# Compiler
CC = gcc

# Source files
SOURCES = src/main.c src/userInteraction.c src/repl.c src/btree.c

# Default Target
all:
	$(CC) $(CFLAGS) -o /bin/pacificStandard $(SOURCES)

# Clean up
clean:
	rm -f main
