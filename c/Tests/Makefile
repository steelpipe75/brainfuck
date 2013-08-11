CC = gcc

CFLAGS = -Wall -W
INCLUDES = -I/usr/local/include -I../Source
LFLAGS = -L/usr/local/lib -lpcunit

TARGET = test_brainfuck.exe

OBJS = main.o
OBJS += test_brainfuck.o
OBJS += brainfuck.o

.PHONY: all clean test cov test-cov

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
	rm -f *.gcda
	rm -f *.gcno
	rm -f  *.info

cov: 
	make CFLAGS="$(CFLAGS) -fprofile-arcs -ftest-coverage" LDFLAGS="$(LDFLAGS) -fprofile-arcs"

test-cov:
	make cov
	make test
	lcov -c -d . -o lcov.info
	lcov -r lcov.info *.h -o lcov-html.info
	genhtml -o html lcov-html.info


main.o : 
test_brainfuck.o : ../Source/brainfuck.h
brainfuck.o : ../Source/brainfuck.h
