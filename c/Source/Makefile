CC = gcc

CFLAGS = -Wall -W

TARGET = brainfuck.exe

OBJS = main.o

all: $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
