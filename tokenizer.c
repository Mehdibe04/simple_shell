#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */
/**
 * **strtoowsSh - transform a double str in2 separated words.
 * @strShll: double str input
 * @dShll: double str delim
 * Return: a ptr to an arr of str, 0 Otherwise
*/

char **strtoowsSh(char *strShll, char *dShll)
{
	int ish, jsh, ksShll, mSh, numbWrdsSh = 0;
	char **sShll;

	if (strShll == NULL || strShll[0] == 0)
		return (NULL);
	if (!dShll)
		dShll = " ";
	for (ish = 0; strShll[ish] != '\0'; ish++)
		if (!deliimfnc(strShll[ish], dShll) && (deliimfnc(strShll[ish + 1]
						, dShll) || !strShll[ish + 1]))
			numbWrdsSh++;

	if (numbWrdsSh == 0)
		return (NULL);
	sShll = malloc((1 + numbWrdsSh) * sizeof(char *));
	if (!sShll)
		return (NULL);
	for (ish = 0, jsh = 0; jsh < numbWrdsSh; jsh++)
	{
		while (deliimfnc(strShll[ish], dShll))
			ish++;
		ksShll = 0;
		while (!deliimfnc(strShll[ish + ksShll], dShll) && strShll[ish + ksShll])
			ksShll++;
		sShll[jsh] = malloc((ksShll + 1) * sizeof(char));
		if (!sShll[jsh])
		{
			for (ksShll = 0; ksShll < jsh; ksShll++)
				free(sShll[ksShll]);
			free(sShll);
			return (NULL);
		}
		for (mSh = 0; mSh < ksShll; mSh++)
			sShll[jsh][mSh] = strShll[ish++];
		sShll[jsh][mSh] = 0;
	}
	sShll[jsh] = NULL;
	return (sShll);
}

/**
 * **strtoowsSh2 - transform a str in2 separated words.
 * @strShll: double str input.
 * @dShll: the delim to seperate with.
 * Return: a ptr to an arr of str, 0 Otherwise.
*/

char **strtoowsSh2(char *strShll, char dShll)
{
	int ish, jsh, ksShll, mSh, numbWrdsSh = 0;
	char **sShll;

	if (strShll == NULL || strShll[0] == 0)
		return (NULL);
	for (ish = 0; strShll[ish] != '\0'; ish++)
		if ((strShll[ish] != dShll && strShll[ish + 1] == dShll) ||
		    (strShll[ish] != dShll && !strShll[ish + 1]
		     ) || strShll[ish + 1] == dShll)
			numbWrdsSh++;
	if (numbWrdsSh == 0)
		return (NULL);
	sShll = malloc((1 + numbWrdsSh) * sizeof(char *));
	if (!sShll)
		return (NULL);
	for (ish = 0, jsh = 0; jsh < numbWrdsSh; jsh++)
	{
		while (strShll[ish] == dShll && strShll[ish] != dShll)
			ish++;
		ksShll = 0;
		while (strShll[ish + ksShll] != dShll && strShll[ish + ksShll]
		 && strShll[ish + ksShll] != dShll)
			ksShll++;
		sShll[jsh] = malloc((ksShll + 1) * sizeof(char));
		if (!sShll[jsh])
		{
			for (ksShll = 0; ksShll < jsh; ksShll++)
				free(sShll[ksShll]);
			free(sShll);
			return (NULL);
		}
		for (mSh = 0; mSh < ksShll; mSh++)
			sShll[jsh][mSh] = strShll[ish++];
		sShll[jsh][mSh] = 0;
	}
	sShll[jsh] = NULL;
	return (sShll);
}

