#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "caesar_ft.c"

#ifdef _WIN32
#define CLRSCR "cls"
#elif __linux__
#define CLRSCR "clear"
#endif

void	title();
void	ft_caesar_encode(char *str, char *base, int decal);
void	ft_caesar_decode(char *str, char *base);
void	clean_chaine(char *chaine);
void	select_base(char *base);
void	put_str(char *str);
