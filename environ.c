#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * _mysetenvfnc - Initializes a new environment variable
 * or modifies an existing one.
 *
 * @infShll: A structure containing potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Always returns 0.
*/

int _mysetenvfnc(info_to_structShll *infShll)
{
        if (infShll->argc != 3)
        {
                _eputsfnc("Incorrect number of arguements\n");
                return (1);
        }
        if (_setenvfnc(infShll, infShll->argv[1], infShll->argv[2]))
                return (0);
        return (1);
}

/**
 * _myShunsetenvfnc - Erases an environment variable.
 *
 * @infShll: A structured set of potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Always returns 0.
*/

int _myShunsetenvfnc(info_to_structShll *infShll)
{
	int ish = 1;

	if (infShll->argc == 1)
	{
		_eputsfnc("Too few arguements.\n");
		return (1);
	}
	for (; ish <= infShll->argc; ish++)
		_unsetenvfnc(infShll, infShll->argv[ish]);

	return (0);
}

/**
 * _myenvfnc - Displays the current system environment.
 *
 * @infShll: A structure that holds potential arguments,
 * maintaining a consistent function prototype.
 *
 * Return: Always returns 0.
*/

int _myenvfnc(info_to_structShll *infShll)
{
        priintSh_lststr(infShll->envirShll);
        return (0);
}

/**
 * populateSh_envir_lstfnc - Fills an environment linked list with data.
 *
 * @infShll: A structure that houses potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Always returns 0.
*/

int populateSh_envir_lstfnc(info_to_structShll *infShll)
{
	list_tShll *nodeeShll = NULL;
	size_t ish = 0;

	for (; environ[ish]; ish++)
		addiingnodSh_end(&nodeeShll, environ[ish], 0);
	infShll->envirShll = nodeeShll;
	return (0);
}

/**
 * _getenvfnc - Retrieves the value of an environment variable.
 *
 * @infShll: A structured collection of potential arguments,
 * ensuring a consistent function prototype.
 * @nameeShll: The name of the environment variable to be queried.
 *
 * Return: Returns the value of the specified environment variable.
*/

char *_getenvfnc(info_to_structShll *infShll, const char *nameeShll)
{
        list_tShll *nodeeShll;
        char *pSh;

	nodeeShll = infShll->envirShll;
        while (nodeeShll)
        {
                pSh = startsSh_witthfnc(nodeeShll->stringShll, nameeShll);
                if (pSh && *pSh)
                        return (pSh);
                nodeeShll = nodeeShll->nextShll;
        }
        return (NULL);
}
