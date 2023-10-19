#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * _setenvfnc - Establish a new envir var
 * or mdfy an exstg one.
 *
 * @infShll: A structur containg pot args.
 * @varrShll: The property of the environment variable.
 * @valSh_ue: The val of the envir var.
 *
 * Result: Always returns 0.
*/

int _setenvfnc(info_to_structShll *infShll, char *varrShll, char *valSh_ue)
{
	char *bufferSh = NULL;
	list_tShll *nodeeShll;
	char *pSh;

	if (!varrShll || !valSh_ue)
		return (0);

	bufferSh = malloc(_strlenfnc(varrShll) + _strlenfnc(valSh_ue) + 2);
	if (!bufferSh)
		return (1);
	_strcpyfnc(bufferSh, varrShll);
	_strcatfnc(bufferSh, "=");
	_strcatfnc(bufferSh, valSh_ue);
	nodeeShll = infShll->envirShll;
	while (nodeeShll)
	{
		pSh = startsSh_witthfnc(nodeeShll->stringShll, varrShll);
		if (pSh && *pSh == '=')
		{
			free(nodeeShll->stringShll);
			nodeeShll->stringShll = bufferSh;
			infShll->env_chgedShll = 1;
			return (0);
		}
		nodeeShll = nodeeShll->nextShll;
	}
	addiingnodSh_end(&(infShll->envirShll), bufferSh, 0);
	free(bufferSh);
	infShll->env_chgedShll = 1;
	return (0);
}

/**
 * _unsetenvfnc - Eliminates an envir var.
 *
 * @infShll: A structur that holds pot args,
 * maintng a csstt func prttype.
 * @varrShll: The proprty of the envir var to be remvd.
 *
 * Return: Returns 1 when the var is sccssflly dlted,
 * 0 otherwise.
*/

int _unsetenvfnc(info_to_structShll *infShll, char *varrShll)
{
        list_tShll *nodeeShll;
        size_t ish;
        char *pSh;

	ish = 0;
	nodeeShll = infShll->envirShll;
        if (!nodeeShll || !varrShll)
                return (0);

        while (nodeeShll)
        {
                pSh = startsSh_witthfnc(nodeeShll->stringShll, varrShll);
                if (pSh && *pSh == '=')
                {
                        infShll->env_chgedShll = deleteSh_nodat_indxfnc(&(infShll->envirShll), ish);
                        ish = 0;
                        nodeeShll = infShll->envirShll;
                        continue;
                }
                nodeeShll = nodeeShll->nextShll;
                ish++;
        }
        return (infShll->env_chgedShll);
}

/**
 * getSh_enviironfnc - Retrieves a copy of the environment
 * as a string array.
 *
 * @infShll: A structur that holds pot args,
 * maintng a csstt func prttype.
 *
 * Return: Always returns 0.
*/

char **getSh_enviironfnc(info_to_structShll *infShll)
{
        if (!infShll->environ || infShll->env_chgedShll)
        {
                infShll->environ = list_tShllo_strings_SHLL_fnc(infShll->envirShll);
                infShll->env_chgedShll = 0;
        }

        return (infShll->environ);
}
