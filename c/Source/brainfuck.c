#include <stdlib.h>
#include "brainfuck.h"

typedef struct BFINTERPRETER{
	int tapesize;
	char *tapeptr;
}BFINTERPRETER;


BFI brainfuck_new(int tapesize)
{
	BFI bfi = NULL;
	char *tapeptr;
	
	if(0 != tapesize){
		bfi = malloc(sizeof(BFINTERPRETER));
		bfi->tapesize = tapesize;
		tapeptr = calloc(tapesize,sizeof(char));
		bfi->tapeptr = tapeptr;
	}
	
	return bfi;
}

int brainfuck_delete(BFI bfi)
{
	int Ret = BFI_ERROR;
	char *tapeptr;
	
	if(NULL != bfi){
		tapeptr = bfi->tapeptr;
		if(NULL != tapeptr){
			free(tapeptr);
		}
		free(bfi);
		Ret = BFI_SUCCESS;
	}
	
	return Ret;
}

extern int brainfuck_get_tapesize(BFI bfi, int *ptr_tapesize)
{
	int Ret = BFI_ERROR;
	int tapesize;
	
	if(NULL != bfi){
		tapesize = bfi->tapesize;
		if(0 != tapesize){
			*ptr_tapesize = tapesize;
			Ret = BFI_SUCCESS;
		}
	}
	
	return Ret;
}

int brainfuck_get_tapeptr(BFI bfi, const char **ptr_tapeptr)
{
	int Ret = BFI_ERROR;
	const char *tapeptr;
	
	if(NULL != bfi){
		tapeptr = bfi->tapeptr;
		if(0 != tapeptr){
			*ptr_tapeptr = tapeptr;
			Ret = BFI_SUCCESS;
		}
	}
	
	return Ret;
}

int brainfuck_check_programbracket(const char *ptr_program, int programsize)
{
	int Ret = BFI_ERROR;
	int count = 0;
	int i;
	
	if(NULL != ptr_program){
		if(0 != programsize){
			for(i = 0; i < programsize; i++){
				switch(ptr_program[i]){
					case '[':
						count++;
						break;
					case ']':
						count--;
						break;
					default:
						break;
				}
				
				if(0 > count){
					break;
				}
			}
			
			if(0 == count){
				Ret = BFI_SUCCESS;
			}
		}
	}
	
	return Ret;
	
}

