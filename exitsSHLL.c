#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * _strncatfnc - Appends one string to another.
 *
 * @dstnSh: The first string.
 * @srccSh: The second string to be appended.
 * @nssh: The maximum number of bytes to be used.
 *
 * Return: Returns the concatenated string.
*/

char *_strncatfnc(char *dstnSh, char *srccSh, int nssh)
{
	int ish = 0, jsh = 0;
	char *sShll;

	sShll = dstnSh;
	while (dstnSh[ish] != '\0')
		ish++;
	while (srccSh[jsh] != '\0' && jsh < nssh)
	{
		dstnSh[ish] = srccSh[jsh];
		ish++;
		jsh++;
	}
	if (jsh < nssh)
		dstnSh[ish] = '\0';
	return (sShll);
}

/**
 * _strchrfnc - Locates a specific character within a string.
 *
 * @sShll: The string to be searched.
 * @cShll: The character to find.
 *
 * Return: Returns a pointer to the memory area in 'sShll'.
*/

char *_strchrfnc(char *sShll, char cShll)
{
	do {
		if (*sShll == cShll)
			return (sShll);
	} while (*sShll++ != '\0');
	return (NULL);
}

/**
 * _strncpyfnc - Copies a string from source to destination.
 *
 * @dstnSh: The destination string for the copy operation.
 * @srccSh: The source string to be copied.
 * @nssh: The maximum number of characters to be copied.
 *
 * Return: Returns the concatenated string.
*/

char *_strncpyfnc(char *dstnSh, char *srccSh, int nssh)
{
        int ish = 0, jsh;
        char *sShll;

	sShll = dstnSh;
        while (srccSh[ish] != '\0' && ish < nssh - 1)
        {
                dstnSh[ish] = srccSh[ish];
                ish++;
        }
        if (ish < nssh)
        {
                jsh = ish;
                while (jsh < nssh)
                {
                        dstnSh[jsh] = '\0';
                        jsh++;
                }
        }
        return (sShll);
}
