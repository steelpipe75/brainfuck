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

extern int brainfuck_get_tapesize(BFI bfi, int *ptr_tapesize)
{
	int Ret = BFI_ERROR;
	
	return Ret;
}
