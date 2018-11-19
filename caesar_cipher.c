#include "caesar_ft.h"

int	main()
{	
	int saisie = 1;
	int choix = 0;
	int run = 1;
	int decal = 0;
	char *base = NULL;
	char *str = NULL;

	base = malloc(sizeof(char) * 200);
	str = malloc(sizeof(char) * 200);

	system(CLRSCR);
	title();

	while (saisie)
	{
		printf(	"===== SELECTION =====\n"
			"1. Encode\n"
			"2. Decode\n"
			"Que voulez vous faire ? [1/2]: ");
		scanf("%d", &choix);
		if (choix != 1 && choix != 2)
			printf("\n\nSaisie invalide.\n");
		else
			saisie = 0;
	}

	saisie = 1;
	system(CLRSCR);
	title();

	if (choix == 1)
	{
		printf("===== ENCODE =====\n");
		select_base(base);
		put_str(str);

		while (saisie)
		{
			printf("Entrer une decal : ");
			scanf("%d", &decal);
			if (decal <= 0)
				printf("\n\nSaisie invalide.\n");
			else
				saisie = 0;
		}
		system(CLRSCR);
		title();
		ft_caesar_encode(str, base, decal);
	}
	else
	{
		choix = 0;
		printf("===== DECODE =====\n");
		select_base(base);
		put_str(str);
		system(CLRSCR);
		title();
		ft_caesar_decode(str, base);
	}
	free(base);
	free(str);

	return 0;
}
