#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * _reallocfnc - it reallocates a Sshl of memo.
 * @pointSh_er: ptr to prvs mallocated Sshl.
 * @olddSizSh: bytee sz of the prvs Sshl.
 * @neewSzSh: bytee sz of the new Sshl.
 *
 * Return: ptr the Sshl name.
 */
void *_reallocfnc(void *pointSh_er, unsigned int olddSizSh
		, unsigned int neewSzSh)
{
	char *pSh;

	if (!pointSh_er)
		return (malloc(neewSzSh));
	if (!neewSzSh)
		return (free(pointSh_er), NULL);
	if (neewSzSh == olddSizSh)
		return (pointSh_er);

	pSh = malloc(neewSzSh);
	if (!pSh)
		return (NULL);

	olddSizSh = olddSizSh < neewSzSh ? olddSizSh : neewSzSh;
	while (olddSizSh--)
		pSh[olddSizSh] = ((char *)pointSh_er)[olddSizSh];
	free(pointSh_er);
	return (pSh);
}

/**
 * fiilefreeeSh - an str of strs to be freed
 * @ptr2ptr: str of strs
*/

void fiilefreeeSh(char **ptr2ptr)
{
        char **aaSh;

	aaSh = ptr2ptr;
        if (!ptr2ptr)
                return;
        while (*ptr2ptr)
                free(*ptr2ptr++);
        free(aaSh);
}

/**
 * _memsetfnc - a cste byte to fill the memo
 * @sShll: the memo area's ptr
 * @bShll: the byte that will fill the sShll
 * @nssh: Amount of bytes needed
 * Return: ptr to d memo area sShll
*/

char *_memsetfnc(char *sShll, char bShll, unsigned int nssh)
{
        unsigned int ish = 0;

        for (; ish < nssh; ish++)
                sShll[ish] = bShll;
        return (sShll);
}
