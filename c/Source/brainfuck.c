#include <stdlib.h>
#include "brainfuck.h"

typedef struct BFINTERPRETER{
	int tapesize;
}BFINTERPRETER;


BFI *brainfuck_new(int tapesize)
{
	BFI *bfi = NULL;
	
	if(0 != tapesize){
		bfi = malloc(sizeof(BFINTERPRETER));
	}
	
	return bfi;
}

int brainfuck_delete(BFI bfi)
{
	int Ret = BFI_ERROR;
	
	if(NULL != bfi){
		free(bfi);
		Ret = BFI_SUCCESS;
	}
	
	return Ret;
}
