#ifndef BRAINFUCK_H_INCLUDED
#define BRAINFUCK_H_INCLUDED

typedef struct BFINTERPRETER* BFI;

#define BFI_SUCCESS	(0)
#define BFI_ERROR	(-1)

extern BFI brainfuck_new(const char *ptr_program, int programsize, int tapesize);
extern int brainfuck_delete(BFI bfi);

extern int brainfuck_get_tapesize(BFI bfi, int *ptr_tapesize);
extern int brainfuck_get_tapeptr(BFI bfi, const char **ptr_tapeptr);

extern int brainfuck_get_programsize(BFI bfi, int *ptr_programsize);
extern int brainfuck_get_programptr(BFI bfi, const char **ptr_programptr);

extern int brainfuck_check_programbracket(const char *ptr_program, int programsize);

#endif /* BRAINFUCK_H_INCLUDED */
