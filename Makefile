IDIR = ./include
CC = clang
STD = c99
CFLAGS = -I$(IDIR) -Wall -Wextra -Wpedantic
TARGET = emu

$(TARGET):
	$(CC) src/*.c -o ./build/$(TARGET) $(CFLAGS) -std=$(STD) 
