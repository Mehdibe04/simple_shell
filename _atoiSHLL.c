#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 *_isalphafnc - checks for alphabetic character
 *@cShll: The character to input
 *Return: 1 if cShll is alphabetic, 0 otherwise
 */

int _isalphafnc(int cShll)
{
	if ((cShll >= 'a' && cShll <= 'z') || (cShll >= 'A' && cShll <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * iintrctvSh - Determines if the shell is in interactive mode
 *
 * @infShll: Pointer to a struct containing shell information
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
*/

int iintrctvSh(info_to_structShll *infShll)
{
        return (isatty(STDIN_FILENO) && infShll->read2fdShll <= 2);
}

/**
 *_atoifnc - converts a string to an integer
 *@sShll: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoifnc(char *sShll)
{
	int ish = 0, sgnShll, flgSh, oputShll;
	unsigned int resltShll;

	sgnShll = 1;
	flgSh = 0;
	resltShll = 0;
	for (;  sShll[ish] != '\0' && flgSh != 2; ish++)
	{
		if (sShll[ish] == '-')
			sgnShll *= -1;

		if (sShll[ish] >= '0' && sShll[ish] <= '9')
		{
			flgSh = 1;
			resltShll *= 10;
			resltShll += (sShll[ish] - '0');
		}
		else if (flgSh == 1)
			flgSh = 2;
	}

	if (sgnShll == -1)
		oputShll = -resltShll;
	else
		oputShll = resltShll;

	return (oputShll);
}

/**
 * deliimfnc - Checks if a character is a delimiter
 * @cShll: The character to check
 * @deliimit: The delimiter string
 * Return: 1 if true, 0 if false
*/

int deliimfnc(char cShll, char *deliimit)
{
        while (*deliimit)
                if (*deliimit++ == cShll)
                        return (1);
        return (0);
}
