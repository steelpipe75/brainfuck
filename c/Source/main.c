#include <stdio.h>
#include "brainfuck.h"

int main(int argc, char *argv[])
{
	char buff[256];
	
	printf("brainfuck\n");
	
	brainfuck_init(buff, sizeof(buff));
	
	return 0;
}
