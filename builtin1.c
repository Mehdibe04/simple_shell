#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * print_alias - Outputs the content of an alias string.
 *
 * @nodeeShll: The alias content to be displayed.
 *
 * Return: Always returns 0 upon successful execution,
 * or 1 in case of an error.
*/

int print_alias(list_tShll *nodeeShll)
{
        char *pSh = NULL, *aaSh = NULL;

        if (nodeeShll)
        {
                pSh = _strchrfnc(nodeeShll->stringShll, '=');
                for (aaSh = nodeeShll->stringShll; aaSh <= pSh; aaSh++)
                        _putcharfnc(*aaSh);
                _putcharfnc('\'');
                _putsfnc(pSh + 1);
                _putsfnc("'\n");
                return (0);
        }
        return (1);
}

/**
 * unset_alias - Assigns an alias to a specific string.
 *
 * @infShll: The parameter structure.
 * @strShll: The chosen string for an alias.
 *
 * Return: Always returns 0 upon success, or 1 if an error occurs.
*/

int unset_alias(info_to_structShll *infShll, char *strShll)
{
	char *pSh = _strchrfnc(strShll, '='), cShll;
	int rettSh;

	if (!pSh)
		return (1);
	cShll = *pSh;
	*pSh = 0;
	rettSh = deleteSh_nodat_indxfnc(&(infShll->aliiasShell),
		nod_iindexSh(infShll->aliiasShell,
			 nodstartssSh(infShll->aliiasShell, strShll, -1)));
	*pSh = cShll;
	return (rettSh);
}

/**
 * set_alias - Defines an alias for a given string.
 *
 * @infShll: The parameter structure.
 * @strShll: The string designated as an alias.
 *
 * Return: Always returns 0 upon success,
 * or 1 if an error occurs.
*/

int set_alias(info_to_structShll *infShll, char *strShll)
{
	char *pSh = _strchrfnc(strShll, '=');

	if (!pSh)
		return (1);
	if (!*++pSh)
		return (unset_alias(infShll, strShll));
	unset_alias(infShll, strShll);
	return (addiingnodSh_end(&(infShll->aliiasShell), strShll, 0) == NULL);
}

/**
 * _myaliasfnc - Simulates the behavior of the alias
 * built-in command (similar to 'man alias').
 *
 * @infShll: A structured set of potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Always returns 0.
*/

int _myaliasfnc(info_to_structShll *infShll)
{
	int ish;
	char *pSh = NULL;
	list_tShll *nodeeShll = NULL;

	ish = 0;
	if (infShll->argc == 1)
	{
		nodeeShll = infShll->aliiasShell;
		while (nodeeShll)
		{
			print_alias(nodeeShll);
			nodeeShll = nodeeShll->nextShll;
		}
		return (0);
	}
	for (ish = 1; infShll->argv[ish]; ish++)
	{
		pSh = _strchrfnc(infShll->argv[ish], '=');
		if (pSh)
			set_alias(infShll, infShll->argv[ish]);
		else
			print_alias(nodstartssSh(infShll->aliiasShell, infShll->argv[ish], '='));
	}
	return (0);
}

/**
 * _myhistoryfnc - Presents the command history,
 * displaying each command with line numbers starting from 0.
 *
 * @infShll: A structured collection of potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Always results in 0.
*/

int _myhistoryfnc(info_to_structShll *infShll)
{
        priintSh_liistSh(infShll->histShll);
        return (0);
}
