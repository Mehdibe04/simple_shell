#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * replace_string_fnc_shll - str changing
 * @olddSh: @ old str
 * @newSh: str input
 *
 * Return: 1 (Success), 0 (Failure)
*/

int replace_string_fnc_shll(char **olddSh, char *newSh)
{
        free(*olddSh);
        *olddSh = newSh;
        return (1);
}

/**
 * replace_alias_fnc_shll - aliass changing in the tokenized_str
 * @infShll: structure's param
 *
 * Return: 1 (Success), 0 (Failure)
*/

int replace_alias_fnc_shll(info_to_structShll *infShll)
{
	int ish = 0;
	list_tShll *nodeeShll;
	char *pSh;

	for (; ish < 10; ish++)
	{
		nodeeShll = nodstartssSh(infShll->aliiasShell, infShll->argv[0], '=');
		if (!nodeeShll)
			return (0);
		free(infShll->argv[0]);
		pSh = _strchrfnc(nodeeShll->stringShll, '=');
		if (!pSh)
			return (0);
		pSh = _strdupfnc(pSh + 1);
		if (!pSh)
			return (0);
		infShll->argv[0] = pSh;
	}
	return (1);
}

/**
 * check_chain_fnc_shll - checks if chaining need to be continued
 * @infShll: the structure of the param
 * @bufferSh: buff's char
 * @pSh: @ of the pos in bufferSh
 * @ish: beginning pos in the bufferSh
 * @lnShll: bufferSh memo space
 *
 * Return: Nothing
*/

void check_chain_fnc_shll(info_to_structShll *infShll
                , char *bufferSh, size_t *pSh, size_t ish, size_t lnShll)
{
        size_t jsh;

	jsh = *pSh;
        if (infShll->cmd_buff_typeShell == CMD_AND_CHAINING)
        {
                if (infShll->statuusShll)
                {
                        bufferSh[ish] = 0;
                        jsh = lnShll;
                }
        }
        if (infShll->cmd_buff_typeShell == CMD_OR_CHAINING)
        {
                if (!infShll->statuusShll)
                {
                        bufferSh[ish] = 0;
                        jsh = lnShll;
		}
        }
        *pSh = jsh;
}

/**
 * replace_vars_fnc_shll - vars changing in d tokenized_str
 * @infShll: a structured param
 *
 * Return: 1 (Success), 0 (Failure)
*/

int replace_vars_fnc_shll(info_to_structShll *infShll)
{
	int ish = 0;
	list_tShll *nodeeShll;

	for (; infShll->argv[ish]; ish++)
	{
		if (infShll->argv[ish][0] != '$' || !infShll->argv[ish][1])
			continue;

		if (!_strcmpfnc(infShll->argv[ish], "$?"))
		{
			replace_string_fnc_shll(&(infShll->argv[ish]),
				_strdupfnc(convrt_numbfnc(infShll->statuusShll, 10, 0)));
			continue;
		}
		if (!_strcmpfnc(infShll->argv[ish], "$$"))
		{
			replace_string_fnc_shll(&(infShll->argv[ish]),
				_strdupfnc(convrt_numbfnc(getpid(), 10, 0)));
			continue;
		}
		nodeeShll = nodstartssSh(infShll->envirShll, &infShll->argv[ish][1], '=');
		if (nodeeShll)
		{
			replace_string_fnc_shll(&(infShll->argv[ish]),
				_strdupfnc(_strchrfnc(nodeeShll->stringShll, '=') + 1));
			continue;
		}
		replace_string_fnc_shll(&infShll->argv[ish], _strdupfnc(""));

	}
	return (0);
}

/**
 * iisChaiinSh - checks for buffers
 * @infShll: param structure
 * @bufferSh: buff
 * @pSh: @ of the pos in the buffSh
 *
 * Return: 1 (Success), 0 (Failure)
*/

int iisChaiinSh(info_to_structShll *infShll, char *bufferSh, size_t *pSh)
{
        size_t jsh;

	jsh = *pSh;
        if (bufferSh[jsh] == '|' && bufferSh[jsh + 1] == '|')
        {
                bufferSh[jsh] = 0;
                jsh++;
                infShll->cmd_buff_typeShell = CMD_OR_CHAINING;
        }
        else if (bufferSh[jsh] == '&' && bufferSh[jsh + 1] == '&')
        {
                bufferSh[jsh] = 0;
                jsh++;
                infShll->cmd_buff_typeShell = CMD_AND_CHAINING;
        }
        else if (bufferSh[jsh] == ';')
        {
                bufferSh[jsh] = 0;
                infShll->cmd_buff_typeShell = CMD_CHAIN_CHAINING;
        }
        else
                return (0);
        *pSh = jsh;
        return (1);
}
