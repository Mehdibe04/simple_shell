#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * _myexitfnc - Concludes the shell operation.
 *
 * @infShll: A structured collection of potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Exits with a specified exit status (0)
 * when `infShll.argv[0]` is not "exit."
*/

int _myexitfnc(info_to_structShll *infShll)
{
	int exiit_chckSh;

	if (infShll->argv[1])
	{
		exiit_chckSh = _erratoifnc(infShll->argv[1]);
		if (exiit_chckSh == -1)
		{
			infShll->statuusShll = 2;
			priintSh_errrfnc(infShll, "Illegal number: ");
			_eputsfnc(infShll->argv[1]);
			_eputcharfnc('\n');
			return (1);
		}
		infShll->errr_numbShll = _erratoifnc(infShll->argv[1]);
		return (-2);
	}
	infShll->errr_numbShll = -1;
	return (-2);
}

/**
 * _mycdfnc - Adjusts the current directory of the process.
 *
 * @infShll: A structured set of potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Always returns 0.
*/

int _mycdfnc(info_to_structShll *infShll)
{
	char *sShll, *dirrSh, buffStr[1024];
	int chdirSh_reett;

	sShll = getcwd(buffStr, 1024);
	if (!sShll)
		_putsfnc("TODO: >>getcwd failure emsg here<<\n");
	if (!infShll->argv[1])
	{
		dirrSh = _getenvfnc(infShll, "HOME=");
		if (!dirrSh)
			chdirSh_reett = /* TODO: what should this be? */
				chdir((dirrSh = _getenvfnc(infShll, "PWD=")) ? dirrSh : "/");
		else
			chdirSh_reett = chdir(dirrSh);
	}
	else if (_strcmpfnc(infShll->argv[1], "-") == 0)
	{
		if (!_getenvfnc(infShll, "OLDPWD="))
		{
			_putsfnc(sShll);
			_putcharfnc('\n');
			return (1);
		}
		_putsfnc(_getenvfnc(infShll, "OLDPWD=")), _putcharfnc('\n');
		chdirSh_reett = chdir((dirrSh = _getenvfnc
					(infShll, "OLDPWD=")) ? dirrSh : "/");
	}
	else
		chdirSh_reett = chdir(infShll->argv[1]);
	if (chdirSh_reett == -1)
	{
		priintSh_errrfnc(infShll, "can't cd to ");
		_eputsfnc(infShll->argv[1]), _eputcharfnc('\n');
	}
	else
	{
		_setenvfnc(infShll, "OLDPWD", _getenvfnc(infShll, "PWD="));
		_setenvfnc(infShll, "PWD", getcwd(buffStr, 1024));
	}
	return (0);
}

/**
 * _myhelpfnc - Provides guidance and support related to shell usage.
 *
 * @infShll: A structured collection of potential arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Always returns 0.
*/

int _myhelpfnc(info_to_structShll *infShll)
{
	char **argSh_arr;

	argSh_arr = infShll->argv;
	_putsfnc("help call works. Function not yet implemented \n");
	if (0)
		_putsfnc(*argSh_arr); /* temp att_unused workaround */
	return (0);
}

