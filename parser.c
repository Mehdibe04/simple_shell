#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * duplicateSh_charssfnc - dup chars
 * @pathstr: str's path
 * @starttShll: idxSh to the starting node
 * @sttpShll: idxSh indicating the stop point
 *
 * Return: ptr to d new buff
*/

char *duplicateSh_charssfnc(char *pathstr, int starttShll, int sttpShll)
{
	static char bufferSh[1024];
	int ish, ksShll;

	ish = 0;
	for (ksShll = 0, ish = starttShll; ish < sttpShll; ish++)
		if (pathstr[ish] != ':')
			bufferSh[ksShll++] = pathstr[ish];
	bufferSh[ksShll] = 0;
	return (bufferSh);
}

/**
 * isSh_comandfnc - checks if the file is an exe cmd
 * @infShll: the infShll structure
 * @pthShll: paath 2 d f
 *
 * Return: 1 (Success), 0 (Failure)
*/

int isSh_comandfnc(info_to_structShll *infShll, char *pthShll)
{
        struct stat st;

        (void)infShll;
        if (!pthShll || stat(pthShll, &st))
                return (0);

        if (st.st_mode & S_IFREG)
        {
                return (1);
        }
        return (0);
}

/**
 * findiingSh_patthfnc - the cmd in the str's path to be found
 * @infShll: the infShll structure
 * @pathstr: str's path
 * @cmmdSh: the cmd to be found
 *
 * Return: full path of the str to be found, 0 Otherwise
*/

char *findiingSh_patthfnc(info_to_structShll *infShll
		, char *pathstr, char *cmmdSh)
{
	int ish, currPositSh;
	char *pthShll;

	ish = 0;
	currPositSh = 0;
	if (!pathstr)
		return (NULL);
	if ((_strlenfnc(cmmdSh) > 2) && startsSh_witthfnc(cmmdSh, "./"))
	{
		if (isSh_comandfnc(infShll, cmmdSh))
			return (cmmdSh);
	}
	while (1)
	{
		if (!pathstr[ish] || pathstr[ish] == ':')
		{
			pthShll = duplicateSh_charssfnc(pathstr, currPositSh, ish);
			if (!*pthShll)
				_strcatfnc(pthShll, cmmdSh);
			else
			{
				_strcatfnc(pthShll, "/");
				_strcatfnc(pthShll, cmmdSh);
			}
			if (isSh_comandfnc(infShll, pthShll))
				return (pthShll);
			if (!pathstr[ish])
				break;
			currPositSh = ish;
		}
		ish++;
	}
	return (NULL);
}

