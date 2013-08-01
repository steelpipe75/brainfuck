#include <stdio.h>
#include "brainfuck.h"

int main(int argc, char *argv[])
{
	BFI bfi;
	
	printf("brainfuck\n");
	
	bfi = brainfuck_new(256);
	brainfuck_delete(bfi);
	
	return 0;
}
