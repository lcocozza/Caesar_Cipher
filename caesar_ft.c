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
		str[i] = base[j];
		j = -1;
	}
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
