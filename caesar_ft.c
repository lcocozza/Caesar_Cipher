void	title(void)
{
	printf(	"  ____                              ____ _       _               \n"
			" / ___|__ _  ___  ___  __ _ _ __   / ___(_)_ __ | |__   ___ _ __ \n"
			"| |   / _` |/ _ \\/ __|/ _` | '__| | |   | | '_ \\| '_ \\ / _ \\ '__|\n"
			"| |__| (_| |  __/\\__ \\ (_| | |    | |___| | |_) | | | |  __/ |   \n"
			" \\____\\__,_|\\___||___/\\__,_|_|     \\____|_| .__/|_| |_|\\___|_|   \n"
			"                                          |_|                    \n");
	printf("\n\n\n");
}

void	ft_caesar_encode(char *str, char *base, int decal)
{	
	int nbBase;
	int j;

	for (nbBase = 0; base[nbBase] != '\0'; nbBase++) ;
	for (int i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; base[j] != str[i]; j++) ;
		if (j + decal > nbBase)
			j = j + decal - nbBase;
		else
			j += decal;
		printf("%c", base[j]);
		str[i] = base[j];
		j = -1;
	}
	printf("\n");
}

void	ft_caesar_decode(char *str, char *base)
{
	int nbBase;
	int i;
	int j;
	char *strC = NULL;

	strC = malloc(sizeof(strlen(str) + 1));

	if (strC == NULL)
		exit(0);

	for (nbBase = 0; base[nbBase] != '\0'; nbBase++) ;
	for (int k = 0; k <= nbBase; k++)
	{
		strcpy(strC, str);
		for (i = 0; strC[i] != '\0'; i++)
		{
			for (j = 0; base[j] != str[i]; j++) ;
			if (j - k < 0)
				j = j - k + nbBase;
			else
				j -= k;
			strC[i] = base[j];
			j = -1;
		}
		printf("%s %d\n", strC, k);
		i = -1;
	}
	free(strC);
}

void	clean_chaine(char *chaine)
{
	for (int i = 0; chaine[i]; i++)
		chaine[i] = '\0';
}

void	select_base(char *base)
{
	int choix = 1;
	int saisie = 1;
	char base1[100] = "abcdefghijklmnopqrtuvwxyzABCDEFGHIJKLMNOPQRTUVWXYZ";
	char base2[100] = "abcdefghijklmnopqrtuvwxyzABCDEFGHIJKLMNOPQRTUVWXYZ0123456789";
	char base3[150] = "abcdefghijklmnopqrtuvwxyzABCDEFGHIJKLMNOPQRTUVWXYZ0123456789 ?!()[]{}-+=_*&^%$#@:;<>.";


	while (saisie)
	{
		printf(	"1. %s\n"
			"2. %s\n"
			"3. %s\n"
			"4. Custom\n"
			"Choisisez une base : ", base1, base2, base3);
		scanf("%d", &choix);
		if (choix < 1 && choix > 4)
			printf("\n\nSaisie ivalide.\n");
		else
			saisie = 0;
	}
	saisie = 1;
	if (choix == 1)
		strcpy(base, base1);
	if (choix == 2)
		strcpy(base, base2);
	if (choix == 3)
		strcpy(base, base3);
	if (choix == 4)
		while (saisie)
		{
			printf("Entrez votre base (200 char max) : ");
			scanf("%s", base);
			if (strlen(base) >= 200)
			{
				printf("\n\nSaisie invalide.\n");
				clean_chaine(base);
			}
			else
				saisie = 0;
		}
}

void	put_str(char *str)
{
	int saisie = 1;

	while (saisie)
	{
		printf("Entrez votre message (200 char max) : ");
		scanf("%s", str);
		if (strlen(str) >= 200)
		{
			printf("\n\nSaisie invalide.\n");
			clean_chaine(str);
		}
		else 
			saisie = 0;
	}
}
