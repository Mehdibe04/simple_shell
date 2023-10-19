#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * startsSh_witthfnc - checks if hyShStk is in the beginning of needlleeSh
 * @hayShStak: str input
 * @needlleeSh: src input
 *
 * Return: nxt char's @ of str input
*/

char *startsSh_witthfnc(const char *hayShStak, const char *needlleeSh)
{
        while (*needlleeSh)
                if (*needlleeSh++ != *hayShStak++)
                        return (NULL);
        return ((char *)hayShStak);
}

/**
 * _strcatfnc - 2 str concatenatg
 * @dstnSh: dest's buff
 * @srccSh: src's buff
 *
 * Return: ptr 2 dest's buff
*/

char *_strcatfnc(char *dstnSh, char *srccSh)
{
        char *rettSh;

	rettSh = dstnSh;
        while (*dstnSh)
                dstnSh++;
        while (*srccSh)
                *dstnSh++ = *srccSh++;
        *dstnSh = *srccSh;
        return (rettSh);
}

/**
 * _strcmpfnc - it compares 2 str.
 * @strSh_1: str 1
 * @strSh_2: str 2
 *
 * Return: -1 if str1 < str2, 1 if str1 > str2, 0 Otherwise
*/

int _strcmpfnc(char *strSh_1, char *strSh_2)
{
	while (*strSh_1 && *strSh_2)
	{
		if (*strSh_1 != *strSh_2)
			return (*strSh_1 - *strSh_2);
		strSh_1++;
		strSh_2++;
	}
	if (*strSh_1 == *strSh_2)
		return (0);
	else
		return (*strSh_1 < *strSh_2 ? -1 : 1);
}

/**
 * _strlenfnc - gets number of char contained in a str
 * @sShll: str input
 *
 * Return: number of chars
*/

int _strlenfnc(char *sShll)
{
        int ish;

	ish = 0;
        if (!sShll)
                return (0);

        while (*sShll++)
                ish++;
        return (ish);
}
