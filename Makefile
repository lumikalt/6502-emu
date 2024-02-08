IDIR = ./include
CC = clang
CFLAGS = -I$(IDIR) -Wall -Wextra -Wpedantic
TARGET = emu

$(TARGET):
	$(CC) src/*.c -o ./build/$(TARGET) $(CFLAGS) 
