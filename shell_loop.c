#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * hsh - the main shell program
 * @infShll: the param infShll struct
 * @av: The arg vect from main program
 *
 * Return: 0 (Success), 1 (Failure)
*/

int hsh(info_to_structShll *infShll, char **av)
{
	ssize_t rsShll;
	int b8ltinRettSh;

	rsShll = 0;
	b8ltinRettSh = 0;
	while (rsShll != -1 && b8ltinRettSh != -2)
	{
		clear_info_fnc_shll(infShll);
		if (iintrctvSh(infShll))
			_putsfnc("$ ");
		_eputcharfnc(BUFFER_FLSH);
		rsShll = gettSh_inptfnc(infShll);
		if (rsShll != -1)
		{
			setSh_iinfofnc(infShll, av);
			b8ltinRettSh = findSh_builtinfnc(infShll);
			if (b8ltinRettSh == -1)
				findSh_comanddfnc(infShll);
		}
		else if (iintrctvSh(infShll))
			_putcharfnc('\n');
		freeSh_iinfofnc(infShll, 0);
	}
	wriite_hstoryfnc(infShll);
	freeSh_iinfofnc(infShll, 1);
	if (!iintrctvSh(infShll) && infShll->statuusShll)
		exit(infShll->statuusShll);
	if (b8ltinRettSh == -2)
	{
		if (infShll->errr_numbShll == -1)
			exit(infShll->statuusShll);
		exit(infShll->errr_numbShll);
	}
	return (b8ltinRettSh);
}

/**
 * forkSh_comaandfnc - finds an exe thrd to run the commd
 * @infShll: the param of the infShll structure
 *
 * Return: Nothing
*/

void forkSh_comaandfnc(info_to_structShll *infShll)
{
        pid_t chiildPiidShll = fork();

	if (chiildPiidShll == -1)
        {
                perror("Error:");
                return;
        }
        if (chiildPiidShll == 0)
        {
                if (execve(infShll->pathShll, infShll->argv
                                        , getSh_enviironfnc(infShll)) == -1)
                {
                        freeSh_iinfofnc(infShll, 1);
                        if (errno == EACCES)
                                exit(126);
                        exit(1);
                }
        }
        else
        {
                wait(&(infShll->statuusShll));
                if (WIFEXITED(infShll->statuusShll))
                {
                        infShll->statuusShll = WEXITSTATUS(infShll->statuusShll);
                        if (infShll->statuusShll == 126)
                                priintSh_errrfnc(infShll, "Permission denied\n");
                }
        }
}

/**
 * findSh_comanddfnc - looks for a specific
 * cmd in the path directory
 * @infShll: the param of the infShll structure
 *
 * Return: Nothing
 */
void findSh_comanddfnc(info_to_structShll *infShll)
{
	char *pthShll = NULL;
	int ish, ksShll;

	infShll->pathShll = infShll->argv[0];
	if (infShll->linecnt_flgShll == 1)
	{
		infShll->line_cntShll++;
		infShll->linecnt_flgShll = 0;
	}
	for (ish = 0, ksShll = 0; infShll->arg[ish]; ish++)
		if (!deliimfnc(infShll->arg[ish], " \t\n"))
			ksShll++;
	if (!ksShll)
		return;

	pthShll = findiingSh_patthfnc(infShll, _getenvfnc(infShll
				, "PATH="), infShll->argv[0]);
	if (pthShll)
	{
		infShll->pathShll = pthShll;
		forkSh_comaandfnc(infShll);
	}
	else
	{
		if ((iintrctvSh(infShll) || _getenvfnc(infShll, "PATH=")
			|| infShll->argv[0][0] == '/') && isSh_comandfnc(infShll, infShll->argv[0]))
			forkSh_comaandfnc(infShll);
		else if (*(infShll->arg) != '\n')
		{
			infShll->statuusShll = 127;
			priintSh_errrfnc(infShll, "not found\n");
		}
	}
}

/**
 * findSh_builtinfnc - the function finds the b8ltin cmd
 * @infShll: the param  of the infShll struct
 *
 * Return: -1 if not_fnd, 0 (Success),
 * 1 (Failure), -2 in exit case
*/

int findSh_builtinfnc(info_to_structShll *infShll)
{
        int ish = 0, b8lt_inShll;
        builtinTblShll b8ltintblShll[] = {
                {"exit", _myexitfnc},
                {"env", _myenvfnc},
                {"help", _myhelpfnc},
                {"history", _myhistoryfnc},
                {"setenv", _mysetenvfnc},
                {"unsetenv", _myShunsetenvfnc},
                {"cd", _mycdfnc},
                {"alias", _myaliasfnc},
                {NULL, NULL}
        };

	b8lt_inShll = -1;
        for (; b8ltintblShll[ish].typeShll; ish++)
                if (_strcmpfnc(infShll->argv[0], b8ltintblShll[ish].typeShll) == 0)
                {
                        infShll->line_cntShll++;
                        b8lt_inShll = b8ltintblShll[ish].fctShll(infShll);
                        break;
                }
        return (b8lt_inShll);
}
