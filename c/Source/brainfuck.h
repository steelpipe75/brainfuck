#ifndef BRAINFUCK_H_INCLUDED
#define BRAINFUCK_H_INCLUDED

typedef struct BFINTERPRETER* BFI;

#define BFI_SUCCESS	(0)
#define BFI_ERROR	(-1)

extern BFI *brainfuck_new(int tapesize);
extern int brainfuck_delete(BFI bfi);

#endif /* BRAINFUCK_H_INCLUDED */
