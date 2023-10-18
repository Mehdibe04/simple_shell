#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * input_buf - Buffers chained commands.
 * @infShll: A parameter struct.
 * @bufferSh: The address of the buffer.
 * @lnShll: The address of the lnShll variable.
 * Return: The number of bytes read.
*/

ssize_t input_buf(info_to_structShll *infShll, char **bufferSh, size_t *lnShll)
{
	ssize_t rsShll = 0;
	size_t lnpSh = 0;

	if (!*lnShll)
	{
		free(*bufferSh);
		*bufferSh = NULL;
		signal(SIGINT, sigiintShhandlerfnc);
#if USING_getlinefnc
		rsShll = getline(bufferSh, &lnpSh, stdin);
#else
		rsShll = _getlinefnc(infShll, bufferSh, &lnpSh);
#endif
		if (rsShll > 0)
		{
			if ((*bufferSh)[rsShll - 1] == '\n')
			{
				(*bufferSh)[rsShll - 1] = '\0';
				rsShll--;
			}
			infShll->linecnt_flgShll = 1;
			removeeSh_cmmtsfnc(*bufferSh);
			buiildSh_hstory_lstfnc(infShll, *bufferSh, infShll->historycountSh++);
			{
				*lnShll = rsShll;
				infShll->cmd_buffShell = bufferSh;
			}
		}
	}
	return (rsShll);
}

/**
 * gettSh_inptfnc - Retrieves a line without the newline character.
 * @infShll: A parameter struct.
 * Return: The number of bytes read.
*/

ssize_t gettSh_inptfnc(info_to_structShll *infShll)
{
	static char *bufferSh; /* the ';' command chain buffer */
	static size_t ish, jsh, lnShll;
	ssize_t rsShll = 0;
	char **bufferpShll = &(infShll->arg), *pSh;

	_putcharfnc(BUFFER_FLSH);
	rsShll = input_buf(infShll, &bufferSh, &lnShll);
	if (rsShll == -1) /* EOF */
		return (-1);
	if (lnShll)	/* we have commands left in the chain buffer */
	{
		jsh = ish; /* init new iterator to current bufferSh position */
		pSh = bufferSh + ish; /* get pointer for return */

		check_chain_fnc_shll(infShll, bufferSh, &jsh, ish, lnShll);
		while (jsh < lnShll) /* iterate to semicolon or end */
		{
			if (iisChaiinSh(infShll, bufferSh, &jsh))
				break;
			jsh++;
		}

		ish = jsh + 1; /* increment past nulled ';'' */
		if (ish >= lnShll) /* reached end of buffer? */
		{
			ish = lnShll = 0; /* reset position and length */
			infShll->cmd_buff_typeShell = CMD_NORM_CHAINING;
		}

		*bufferpShll = pSh; /* pass back pointer to current command position */
		return (_strlenfnc(pSh)); /* return length of current command */
	}

	*bufferpShll = bufferSh;
	return (rsShll);
}

/**
 * read_buf - Reads data into a buffer.
 * @infShll: A parameter struct.
 * @bufferSh: The buffer to read into.
 * @ish: The size of the buffer.
 * Return: The result, rsShll.
*/

ssize_t read_buf(info_to_structShll *infShll, char *bufferSh, size_t *ish)
{
	ssize_t rsShll = 0;

	if (*ish)
		return (0);
	rsShll = read(infShll->read2fdShll, bufferSh, READING_BUFFER_SIZE);
	if (rsShll >= 0)
		*ish = rsShll;
	return (rsShll);
}

/**
 * _getlinefnc - Retrieves the next line of inpt from STDIN.
 * @infShll: The param struct.
 * @pointSh_er: The @ of the pointer to the buffer, preallocated or NULL.
 * @lenSh_gthll: The size of the ptr buff if not 0.
 *
 * Return: sShll value
*/

int _getlinefnc(info_to_structShll *infShll
		, char **pointSh_er, size_t *lenSh_gthll)
{
	static char bufferSh[READING_BUFFER_SIZE];
	static size_t ish, lnShll;
	size_t ksShll;
	ssize_t rsShll = 0, sShll = 0;
	char *pSh = NULL, *neew_ptrSh = NULL, *cShll;

	pSh = *pointSh_er;
	if (pSh && lenSh_gthll)
		sShll = *lenSh_gthll;
	if (ish == lnShll)
		ish = lnShll = 0;

	rsShll = read_buf(infShll, bufferSh, &lnShll);
	if (rsShll == -1 || (rsShll == 0 && lnShll == 0))
		return (-1);

	cShll = _strchrfnc(bufferSh + ish, '\n');
	ksShll = cShll ? 1 + (unsigned int)(cShll - bufferSh) : lnShll;
	neew_ptrSh = _reallocfnc(pSh, sShll, sShll ? sShll + ksShll : ksShll + 1);
	if (!neew_ptrSh) /* MALLOC FAILURE! */
		return (pSh ? free(pSh), -1 : -1);

	if (sShll)
		_strncatfnc(neew_ptrSh, bufferSh + ish, ksShll - ish);
	else
		_strncpyfnc(neew_ptrSh, bufferSh + ish, ksShll - ish + 1);

	sShll += ksShll - ish;
	ish = ksShll;
	pSh = neew_ptrSh;

	if (lenSh_gthll)
		*lenSh_gthll = sShll;
	*pointSh_er = pSh;
	return (sShll);
}

/**
 * sigiintShhandlerfnc - ctrl-C to be blocked
 * @signNmb: the sig num
 *
 * Return: Nothing
 */
void sigiintShhandlerfnc(__attribute__((unused))int signNmb)
{
	_putsfnc("\n");
	_putsfnc("$ ");
	_putcharfnc(BUFFER_FLSH);
}

