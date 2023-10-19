#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * renumbrSh_hstoryfnc - one the change is made,
 * it renumbs d hstry linked lst
 * @infShll: Strct that contains potential args.
 *
 * Return: hstrycnt (new one)
 */
int renumbrSh_hstoryfnc(info_to_structShll *infShll)
{
        list_tShll *nodeeShll;
        int ish;

	ish = 0;
	nodeeShll = infShll->histShll;
        while (nodeeShll)
        {
                nodeeShll->numShll = ish++;
                nodeeShll = nodeeShll->nextShll;
        }
        return (infShll->historycountSh = ish);
}

/**
 * buildSh_hstory_lstfnc - Appends an entry to a hstry linked lst.
 * @infShll: The structure that contains potential args.
 * @bufferSh: The buffer.
 * @linecntSh: The history line count (hstrycount).
 *
 * Return: 0 (Success)
*/

int buiildSh_hstory_lstfnc(info_to_structShll *infShll
                , char *bufferSh, int linecntSh)
{
        list_tShll *nodeeShll = NULL;

        if (infShll->histShll)
                nodeeShll = infShll->histShll;
        addiingnodSh_end(&nodeeShll, bufferSh, linecntSh);

        if (!infShll->histShll)
                infShll->histShll = nodeeShll;
        return (0);
}

/**
 * get_hstry_fnc - Retrieves the history file.
 * @infShll: The param struct.
 *
 * Return: An allocated str that should contain the hist file.
*/

char *get_hstry_fnc(info_to_structShll *infShll)
{
	char *bufferSh, *dirrSh = _getenvfnc(infShll, "HOME=");

	if (!dirrSh)
		return (NULL);
	bufferSh = malloc(
		sizeof(char) * (_strlenfnc(dirrSh) + _strlenfnc(HIST_FILE_SHLL) + 2)
	);
	if (!bufferSh)
		return (NULL);
	bufferSh[0] = 0;
	_strcpyfnc(bufferSh, dirrSh);
	_strcatfnc(bufferSh, "/");
	_strcatfnc(bufferSh, HIST_FILE_SHLL);
	return (bufferSh);
}

/**
 * readSh_hstoryfnc - Reads historical data from a file.
 * @infShll: The parameter structure.
 *
 * Returns The number of historical records read
 * on success, 0 otherwise.
*/

int readSh_hstoryfnc(info_to_structShll *infShll)
{
	int ish, lasttSh, linecntSh;
	ssize_t fddSh, rdleenShll, fsizzeSh;
	struct stat st;
	char *bufferSh = NULL, *fnameShll;

	lasttSh = 0;
	linecntSh = 0;
	fsizzeSh = 0;
	fnameShll = get_hstry_fnc(infShll);
	if (!fnameShll)
		return (0);

	fddSh = open(fnameShll, O_RDONLY);
	free(fnameShll);
	if (fddSh == -1)
		return (0);
	if (!fstat(fddSh, &st))
		fsizzeSh = st.st_size;
	if (fsizzeSh < 2)
		return (0);
	bufferSh = malloc(sizeof(char) * (fsizzeSh + 1));
	if (!bufferSh)
		return (0);
	rdleenShll = read(fddSh, bufferSh, fsizzeSh);
	bufferSh[fsizzeSh] = 0;
	if (rdleenShll <= 0)
		return (free(bufferSh), 0);
	close(fddSh);
	for (ish = 0; ish < fsizzeSh; ish++)
		if (bufferSh[ish] == '\n')
		{
			bufferSh[ish] = 0;
			buiildSh_hstory_lstfnc(infShll, bufferSh + lasttSh, linecntSh++);
			lasttSh = ish + 1;
		}
	if (lasttSh != ish)
		buiildSh_hstory_lstfnc(infShll, bufferSh + lasttSh, linecntSh++);
	free(bufferSh);
	infShll->historycountSh = linecntSh;
	while (infShll->historycountSh-- >= HIST_MAX_SHLL)
		deleteSh_nodat_indxfnc(&(infShll->histShll), 0);
	renumbrSh_hstoryfnc(infShll);
	return (infShll->historycountSh);
}

/**
 * wriite_hstoryfnc - appnds to an existg file or create an new file
 * @infShll: the param strct
 *
 * Return: 1 (Success), -1 Otherwise
*/

int wriite_hstoryfnc(info_to_structShll *infShll)
{
        ssize_t fddSh;
        char *fnameShll;
        list_tShll *nodeeShll = NULL;

	fnameShll = get_hstry_fnc(infShll);
        if (!fnameShll)
                return (-1);

        fddSh = open(fnameShll, O_CREAT | O_TRUNC | O_RDWR, 0644);
        free(fnameShll);
        if (fddSh == -1)
                return (-1);
        for (nodeeShll = infShll->histShll; nodeeShll
                        ; nodeeShll = nodeeShll->nextShll)
        {
                _putsfncfdfnc(nodeeShll->stringShll, fddSh);
                _putfdfnc('\n', fddSh);
        }
        _putfdfnc(BUFFER_FLSH, fddSh);
        close(fddSh);
        return (1);
}
