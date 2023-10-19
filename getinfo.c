#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * freeSh_iinfofnc - info_to_structShll struct fields to be freed
 * @infShll: Struct @
 * @alShlll: T if freeing all fields was done
 *
 * Return: Nothing
*/

void freeSh_iinfofnc(info_to_structShll *infShll, int alShlll)
{
	fiilefreeeSh(infShll->argv);
	infShll->argv = NULL;
	infShll->pathShll = NULL;
	if (alShlll)
	{
		if (!infShll->cmd_buffShell)
			free(infShll->arg);
		if (infShll->envirShll)
			free_listfnc(&(infShll->envirShll));
		if (infShll->histShll)
			free_listfnc(&(infShll->histShll));
		if (infShll->aliiasShell)
			free_listfnc(&(infShll->aliiasShell));
		fiilefreeeSh(infShll->environ);
			infShll->environ = NULL;
		bufferfreeeSh((void **)infShll->cmd_buffShell);
		if (infShll->read2fdShll > 2)
			close(infShll->read2fdShll);
		_putcharfnc(BUFFER_FLSH);
	}
}

/**
 * setSh_iinfofnc - info_to_structShll to be initialized
 * @infShll: Struct @
 * @av: Arg vect
 *
 * Return: Nothing
*/

void setSh_iinfofnc(info_to_structShll *infShll, char **av)
{
        int ish;

	ish = 0;
        infShll->fnameShll = av[0];
        if (infShll->arg)
        {
                infShll->argv = strtoowsSh(infShll->arg, " \t");
                if (!infShll->argv)
                {

                        infShll->argv = malloc(sizeof(char *) * 2);
                        if (infShll->argv)
                        {
                                infShll->argv[0] = _strdupfnc(infShll->arg);
                                infShll->argv[1] = NULL;
                        }
                }
                for (ish = 0; infShll->argv && infShll->argv[ish]; ish++)
                        ;
                infShll->argc = ish;

                replace_alias_fnc_shll(infShll);
                replace_vars_fnc_shll(infShll);
        }
}

/**
 * clear_info_fnc_shll - info_to_structShll struct to be initialized
 * @infShll: Struct @
 *
 * Return: Nothing
*/

void clear_info_fnc_shll(info_to_structShll *infShll)
{
        infShll->arg = NULL;
        infShll->argv = NULL;
        infShll->pathShll = NULL;
        infShll->argc = 0;
}
