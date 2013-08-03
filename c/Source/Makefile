CC = gcc

CFLAGS = -Wall -W

TARGET = brainfuck.exe

OBJS = main.o
OBJS += brainfuck.o

.PHONY: all clean

all: $(TARGET)

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f *.o $(TARGET)

main.o: brainfuck.h
brainfuck.o: brainfuck.h
