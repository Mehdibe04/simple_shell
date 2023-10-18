#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * _strcpyfnc - the function cpy a string
 * @dstnSh: dest
 * @srccSh: src
 *
 * Return: ptr to dest
*/

char *_strcpyfnc(char *dstnSh, char *srccSh)
{
	int ish = 0;

	if (dstnSh == srccSh || srccSh == 0)
		return (dstnSh);
	while (srccSh[ish])
	{
		dstnSh[ish] = srccSh[ish];
		ish++;
	}
	dstnSh[ish] = 0;
	return (dstnSh);
}

/**
 * _strdupfnc - it dup the str
 * @strShll: d str to be dupted
 *
 * Return: ptr to d dup str
*/

char *_strdupfnc(const char *strShll)
{
	int lenSh_gthll = 0;
	char *rettSh;

	if (strShll == NULL)
		return (NULL);
	while (*strShll++)
		lenSh_gthll++;
	rettSh = malloc(sizeof(char) * (lenSh_gthll + 1));
	if (!rettSh)
		return (NULL);
	for (lenSh_gthll++; lenSh_gthll--;)
		rettSh[lenSh_gthll] = *--strShll;
	return (rettSh);
}

/**
 *_putsfnc - shows an str as an input
 *@strShll: d str 2 be prnted
 *
 * Return: returns nothing
*/

void _putsfnc(char *strShll)
{
	int ish = 0;

	if (!strShll)
		return;
	while (strShll[ish] != '\0')
	{
		_putcharfnc(strShll[ish]);
		ish++;
	}
}

/**
 * _putcharfnc - outputs d char cShll the standard num 1
 * @cShll: d char 2 be prnted
 *
 * Return: 1 (Success), -1 (Failure).
*/

int _putcharfnc(char cShll)
{
	static int ish;
	static char bufferSh[WRITE_BUFFER_SIZE];

	if (cShll == BUFFER_FLSH || ish >= WRITE_BUFFER_SIZE)
	{
		write(1, bufferSh, ish);
		ish = 0;
	}
	if (cShll != BUFFER_FLSH)
		bufferSh[ish++] = cShll;
	return (1);
}

