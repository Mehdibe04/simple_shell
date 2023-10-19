#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * main - main program
 * @ac: args numbers
 * @av: list of args
 *
 * Return: 0 (Success), 1 (Failure)
*/

int main(int ac, char **av)
{
	info_to_structShll infShll[] = { INIT_CASE };
	int fddSh;

	fddSh = 2;
	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fddSh)
		: "r" (fddSh));
	if (ac == 2)
	{
		fddSh = open(av[1], O_RDONLY);
		if (fddSh == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputsfnc(av[0]);
				_eputsfnc(": 0: Can't open ");
				_eputsfnc(av[1]);
				_eputcharfnc('\n');
				_eputcharfnc(BUFFER_FLSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		infShll->read2fdShll = fddSh;
	}
	populateSh_envir_lstfnc(infShll);
	readSh_hstoryfnc(infShll);
	hsh(infShll, av);
	return (EXIT_SUCCESS);
}

