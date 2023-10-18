#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * getSh_enviironfnc - Retrieves a copy of the environment
 * as a string array.
 *
 * @infShll: A structure that holds potential arguments,
 * maintaining a consistent function prototype.
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

/**
 * _unsetenvfnc - Eliminates an environment variable.
 *
 * @infShll: A structure that holds potential arguments,
 * maintaining a consistent function prototype.
 * @varrShll: The property of the environment variable to be removed.
 *
 * Return: Returns 1 when the variable is successfully deleted,
 * or 0 otherwise.
*/

int _unsetenvfnc(info_to_structShll *infShll, char *varrShll)
{
	list_tShll *nodeeShll = infShll->envirShll;
	size_t ish = 0;
	char *pSh;

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
 * _setenvfnc - Establish a new environment variable
 * or modify an existing one.
 *
 * @infShll: A structure containing potential arguments.
 * @varrShll: The property of the environment variable.
 * @valSh_ue: The value of the environment variable.
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

