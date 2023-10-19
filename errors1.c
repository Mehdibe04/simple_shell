#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * removeeSh_cmmtsfnc - Replaces the first occurrence of '#' with '\0' in a string.
 *
 * @bufferSh: The string to be modified.
 *
 * Return: Always returns 0.
*/

void removeeSh_cmmtsfnc(char *bufferSh)
{
        int ish = 0;

        for (; bufferSh[ish] != '\0'; ish++)
                if (bufferSh[ish] == '#' && (!ish || bufferSh[ish - 1] == ' '))
                {
                        bufferSh[ish] = '\0';
                        break;
                }
}

/**
 * _erratoifnc - Converts a string into an integer.
 *
 * @sShll: The string to be transformed.
 *
 * Return: Returns 0 if no numeric values are found in the string;
 * otherwise, it provides the converted integer.
 * In case of an error, it returns -1.
*/

int _erratoifnc(char *sShll)
{
        int ish;
        unsigned long int resltShll;

	resltShll = 0;
        if (*sShll == '+')
                sShll++;
        for (ish = 0;  sShll[ish] != '\0'; ish++)
        {
                if (sShll[ish] >= '0' && sShll[ish] <= '9')
                {
                        resltShll *= 10;
                        resltShll += (sShll[ish] - '0');
                        if (resltShll > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (resltShll);
}

/**
 * printSh_ddfnc - Outputs a decimal (integer) number in base 10.
 *
 * @inpuuttSh: The number to be displayed.
 * @fddSh: The file descriptor used for output.
 *
 * Return: Returns the number of characters printed.
*/

int printSh_ddfnc(int inpuuttSh, int fddSh)
{
	int (*__putcharsShfnc)(char) = _putcharfnc;
	int ish, cntSh;
	unsigned int abs_Shll, currShll;

	cntSh = 0;
	if (fddSh == STDERR_FILENO)
		__putcharsShfnc = _eputcharfnc;
	if (inpuuttSh < 0)
	{
		abs_Shll = -inpuuttSh;
		__putcharsShfnc('-');
		cntSh++;
	}
	else
		abs_Shll = inpuuttSh;
	currShll = abs_Shll;
	for (ish = 1000000000; ish > 1; ish /= 10)
	{
		if (abs_Shll / ish)
		{
			__putcharsShfnc('0' + currShll / ish);
			cntSh++;
		}
		currShll %= ish;
	}
	__putcharsShfnc('0' + currShll);
	cntSh++;

	return (cntSh);
}

/**
 * convrt_numbfnc - A conversion function, akin to itoa.
 *
 * @numbSh: The number to be converted.
 * @baseeShll: The base for the conversion.
 * @flgsSh: Flags used as arguments.
 *
 * Return: Returns a string representation of the number.
*/

char *convrt_numbfnc(long int numbSh, int baseeShll, int flgsSh)
{
	static char *arrShll;
	static char buffStr[50];
	char sgnShll;
	char *pointSh_er;
	unsigned long nssh;

	sgnShll = 0;
	nssh = numbSh;
	if (!(flgsSh & CNVRT_UNSIGNED) && numbSh < 0)
	{
		nssh = -numbSh;
		sgnShll = '-';
	}
	arrShll = flgsSh & CNVRT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointSh_er = &buffStr[49];
	*pointSh_er = '\0';

	do	{
		*--pointSh_er = arrShll[nssh % baseeShll];
		nssh /= baseeShll;
	} while (nssh != 0);

	if (sgnShll)
		*--pointSh_er = sgnShll;
	return (pointSh_er);
}

/**
 * priintSh_errrfnc - Outputs an error message.
 *
 * @infShll: The parameter and return infShll struct.
 * @estrrSh: The string containing the specific error type.
 *
 * Return: Returns 0 if the operation is successful,
 * or -1 in the event of an error.
*/

void priintSh_errrfnc(info_to_structShll *infShll, char *estrrSh)
{
        _eputsfnc(infShll->fnameShll);
        _eputsfnc(": ");
        printSh_ddfnc(infShll->line_cntShll, STDERR_FILENO);
        _eputsfnc(": ");
        _eputsfnc(infShll->argv[0]);
        _eputsfnc(": ");
        _eputsfnc(estrrSh);
}
