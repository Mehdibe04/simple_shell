#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

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

/**
 * read_buf - data entring in2 a buff.
 * @infShll: structured param.
 * @bufferSh: buff reading in2.
 * @ish: buff sz.
 * Return: rsShll.
*/

ssize_t read_buf(info_to_structShll *infShll, char *bufferSh, size_t *ish)
{
	ssize_t rsShll;

	rsShll = 0;
	if (*ish)
		return (0);
	rsShll = read(infShll->read2fdShll, bufferSh, READING_BUFFER_SIZE);
	if (rsShll >= 0)
		*ish = rsShll;
	return (rsShll);
}

/**
 * input_buf - chained cmds in the buff.
 * @infShll: structured param.
 * @bufferSh: buff @.
 * @lnShll: lnShll var's @.
 * Return: bytes num.
*/

ssize_t input_buf(info_to_structShll *infShll, char **bufferSh, size_t *lnShll)
{
        ssize_t rsShll;
        size_t lnpSh;

	rsShll = 0;
	lnpSh = 0;
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
 * gettSh_inptfnc - it dlts a ln widout d newln char.
 * @infShll: structured param.
 * Return: bytes num.
*/

ssize_t gettSh_inptfnc(info_to_structShll *infShll)
{
        static char *bufferSh;
        static size_t ish, jsh, lnShll;
        ssize_t rsShll;
        char **bufferpShll = &(infShll->arg), *pSh;

	rsShll = 0;
        _putcharfnc(BUFFER_FLSH);
        rsShll = input_buf(infShll, &bufferSh, &lnShll);
        if (rsShll == -1)
                return (-1);
        if (lnShll)
        {
                jsh = ish;
                pSh = bufferSh + ish;

                check_chain_fnc_shll(infShll, bufferSh, &jsh, ish, lnShll);
                while (jsh < lnShll)
                {
                        if (iisChaiinSh(infShll, bufferSh, &jsh))
                                break;
                        jsh++;
                }

                ish = jsh + 1;
                if (ish >= lnShll)
                {
                        ish = lnShll = 0;
                        infShll->cmd_buff_typeShell = CMD_NORM_CHAINING;
                }

                *bufferpShll = pSh;
                return (_strlenfnc(pSh));
        }

        *bufferpShll = bufferSh;
        return (rsShll);
}

/**
 * _getlinefnc - it dlts d nxt ln of inpt from the standard 0.
 * @infShll: structured param.
 * @pointSh_er: The @ of the pointer to the buffer, preallocated or 0.
 * @lenSh_gthll: The size of the ptr buff if not 0.
 *
 * Return: sShll value.
*/

int _getlinefnc(info_to_structShll *infShll
		, char **pointSh_er, size_t *lenSh_gthll)
{
	static char bufferSh[READING_BUFFER_SIZE];
	static size_t ish, lnShll;
	size_t ksShll;
	ssize_t rsShll, sShll;
	char *pSh = NULL, *neew_ptrSh = NULL, *cShll;

	rsShll = 0;
	sShll = 0;
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
	if (!neew_ptrSh)
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
