# Compiler
CC = gcc
CFLAGS = -Wall -g -I../include

# Source files
SOURCES = src/main.c src/userInteraction.c src/db.c src/customerDbInteraction.c src/account.c
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
