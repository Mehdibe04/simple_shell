#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * _putfdfnc - Writes the character 'cShll' to the specified
 * file descriptor 'fddSh'.
 *
 * @cShll: The character to be printed.
 * @fddSh: The file descriptor used for output.
 *
 * Return: Returns 1 upon successful execution. In the event
 * of an error, it returns -1, setting errno appropriately.
*/

int _putfdfnc(char cShll, int fddSh)
{
	static int ish;
	static char bufferSh[WRITE_BUFFER_SIZE];

	if (cShll == BUFFER_FLSH || ish >= WRITE_BUFFER_SIZE)
	{
		write(fddSh, bufferSh, ish);
		ish = 0;
	}
	if (cShll != BUFFER_FLSH)
		bufferSh[ish++] = cShll;
	return (1);
}

/**
 * _eputsfnc - Prints a provided string.
 *
 * @strShll: The string to be displayed.
 *
 * Return: This function does not return a value.
*/

void _eputsfnc(char *strShll)
{
        int ish;

	ish = 0;
        if (!strShll)
                return;
        while (strShll[ish] != '\0')
        {
                _eputcharfnc(strShll[ish]);
                ish++;
        }
}

/**
 * _putsfncfdfnc - Outputs a provided string to
 * the specified file descriptor.
 *
 * @strShll: The string to be displayed.
 * @fddSh: The file descriptor used for output.
 *
 * Return: Returns the number of characters written.
*/

int _putsfncfdfnc(char *strShll, int fddSh)
{
	int ish;

	ish = 0;
	if (!strShll)
		return (0);
	while (*strShll)
		ish += _putfdfnc(*strShll++, fddSh);
	return (ish);
}

/**
 * _eputcharfnc - Writes a character 'cShll'
 * to the standard error output.
 *
 * @cShll: The character to be written.
 *
 * Return: Returns 1 upon successful execution. In the event
 * of an error, it returns -1, setting errno accordingly.
*/

int _eputcharfnc(char cShll)
{
        static int ish;
        static char bufferSh[WRITE_BUFFER_SIZE];

        if (cShll == BUFFER_FLSH || ish >= WRITE_BUFFER_SIZE)
        {
                write(2, bufferSh, ish);
                ish = 0;
        }
        if (cShll != BUFFER_FLSH)
                bufferSh[ish++] = cShll;
        return (1);
}
