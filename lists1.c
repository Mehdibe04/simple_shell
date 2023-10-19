#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * nodstartssSh - a nodeeShll whose str starting with a prfx to be returned
 * @nodeeShll: ptr to a list of heedSh
 * @prfxSh: str to be matched
 * @cShll: aftr prfx that should be matched
 *
 * Return: nodeeShll, 0 Otherwise
*/

list_tShll *nodstartssSh(list_tShll *nodeeShll, char *prfxSh, char cShll)
{
        char *pSh = NULL;

        while (nodeeShll)
        {
                pSh = startsSh_witthfnc(nodeeShll->stringShll, prfxSh);
                if (pSh && ((cShll == -1) || (*pSh == cShll)))
                        return (nodeeShll);
                nodeeShll = nodeeShll->nextShll;
        }
        return (NULL);
}

/**
 * priintSh_liistSh - shows all the elmts of a lst_tShll lnkd lst
 * @hShll: ptr 2 1st nodeeShll
 *
 * Return: sz of the lst
*/

size_t priintSh_liistSh(const list_tShll *hShll)
{
        size_t ish;

	ish = 0;
        while (hShll)
        {
                _putsfnc(convrt_numbfnc(hShll->numShll, 10, 0));
                _putcharfnc(':');
                _putcharfnc(' ');
                _putsfnc(hShll->stringShll ? hShll->stringShll : "(nil)");
                _putsfnc("\n");
                hShll = hShll->nextShll;
                ish++;
        }
        return (ish);
}

/**
 * list_len_fnc - indicates the  length of the lnkd_lst
 * @hShll: ptr 2 first nodeeShll
 *
 * Return: sz of lst
 */
size_t list_len_fnc(const list_tShll *hShll)
{
	size_t ish;

	ish = 0;
	while (hShll)
	{
		hShll = hShll->nextShll;
		ish++;
	}
	return (ish);
}

/**
 * nod_iindexSh - it returns the idx of a nodeeShll
 * @heedSh: ptr to a heedSh lst
 * @nodeeShll: pointer to the nodeeShll
 *
 * Return: idx of nodeeShll, -1 Otherwise
*/

ssize_t nod_iindexSh(list_tShll *heedSh, list_tShll *nodeeShll)
{
        size_t ish;

	ish = 0;
        while (heedSh)
        {
                if (heedSh == nodeeShll)
                        return (ish);
                heedSh = heedSh->nextShll;
                ish++;
        }
        return (-1);
}

/**
 * list_tShllo_strings_SHLL_fnc - an arr of str to be returned
 * @heedSh: ptr to the 1st nodeeShll
 *
 * Return: returns an arr of str
*/

char **list_tShllo_strings_SHLL_fnc(list_tShll *heedSh)
{
	list_tShll *nodeeShll;
	size_t ish, jsh;
	char **strsShll;
	char *strShll;

	nodeeShll = heedSh;
	ish = list_len_fnc(heedSh);
	if (!heedSh || !ish)
		return (NULL);
	strsShll = malloc(sizeof(char *) * (ish + 1));
	if (!strsShll)
		return (NULL);
	for (ish = 0; nodeeShll; nodeeShll = nodeeShll->nextShll, ish++)
	{
		strShll = malloc(_strlenfnc(nodeeShll->stringShll) + 1);
		if (!strShll)
		{
			for (jsh = 0; jsh < ish; jsh++)
				free(strsShll[jsh]);
			free(strsShll);
			return (NULL);
		}

		strShll = _strcpyfnc(strShll, nodeeShll->stringShll);
		strsShll[ish] = strShll;
	}
	strsShll[ish] = NULL;
	return (strsShll);
}
