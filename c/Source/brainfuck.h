#ifndef BRAINFUCK_H_INCLUDED
#define BRAINFUCK_H_INCLUDED

typedef struct BFINTERPRETER* BFI;
typedef int(*BFI_Putchar)(int c);
typedef int(*BFI_Getchar)(void);

#define BFI_SUCCESS		(0)
#define BFI_ERROR	(-1)

extern BFI brainfuck_new(const char *ptr_program, int programsize, int tapesize);
extern int brainfuck_delete(BFI bfi);

extern int brainfuck_step(BFI bfi);

extern int brainfuck_get_programcounter(BFI bfi, int *ptr_programcounter);
extern int brainfuck_get_tapecounter(BFI bfi, int *ptr_tapecounter);

extern int brainfuck_set_putchar(BFI bfi, BFI_Putchar func);
extern int brainfuck_set_getchar(BFI bfi, BFI_Getchar func);
extern int brainfuck_get_putchar(BFI bfi, BFI_Putchar *ptr_func);
extern int brainfuck_get_getchar(BFI bfi, BFI_Getchar *ptr_func);

extern int brainfuck_get_tapesize(BFI bfi, int *ptr_tapesize);
extern int brainfuck_get_tapeptr(BFI bfi, const int **ptr_tapeptr);

extern int brainfuck_get_programsize(BFI bfi, int *ptr_programsize);
extern int brainfuck_get_programptr(BFI bfi, const char **ptr_programptr);

extern int brainfuck_check_programbracket(const char *ptr_program, int programsize);

#endif /* BRAINFUCK_H_INCLUDED */
