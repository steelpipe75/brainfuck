CC = gcc

CFLAGS = -Wall -W
INCLUDES = -I/usr/local/include -I../Source
LFLAGS = -L/usr/local/lib -lpcunit

TARGET = test_brainfuck.exe

OBJS = main.o
OBJS += test_brainfuck.o
OBJS += brainfuck.o

.PHONY: all clean test

all: $(TARGET)

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

brainfuck.o: ../Source/brainfuck.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LFLAGS)

test: all
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

