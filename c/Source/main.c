#include <stdio.h>
#include "brainfuck.h"

int main(int argc, char *argv[])
{
	BFI bfi;
	char program[] = "+";
	
	printf("brainfuck\n");
	
	bfi = brainfuck_new(program, sizeof(program)/sizeof(program[0]), 256);
	brainfuck_delete(bfi);
	
	return 0;
}
