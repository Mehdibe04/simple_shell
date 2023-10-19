#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * deleteSh_nodat_indxfnc - nodeeShll at a certain idxSh to be dlted
 * @heedSh: @ of the  ptr to the 1st nodeeShll
 * @indxSh: indxSh of nodeeShll to be dlted
 *
 * Return: 1 (Success), 0 Otherwise
*/

int deleteSh_nodat_indxfnc(list_tShll **heedSh, unsigned int indxSh)
{
        list_tShll *nodeeShll, *prv_noodSh;
        unsigned int ish;

	ish = 0;
        if (!heedSh || !*heedSh)
                return (0);

        if (!indxSh)
        {
                nodeeShll = *heedSh;
                *heedSh = (*heedSh)->nextShll;
                free(nodeeShll->stringShll);
                free(nodeeShll);
                return (1);
        }
        nodeeShll = *heedSh;
        while (nodeeShll)
        {
                if (ish == indxSh)
                {
                        prv_noodSh->nextShll = nodeeShll->nextShll;
                        free(nodeeShll->stringShll);
                        free(nodeeShll);
                        return (1);
                }
                ish++;
                prv_noodSh = nodeeShll;
                nodeeShll = nodeeShll->nextShll;
        }
        return (0);
}

/**
 * addiingnodSh - nodeeShll to d beginning of d lst to be added
 * @heedSh: @ of ptr to the start of the nodeeShll
 * @strShll: fld of a nodeeShll
 * @numbSh: the nodeeShll idxSh that will be used by nodeeShll
 *
 * Return: sz of the lst
*/

list_tShll *addiingnodSh(list_tShll **heedSh, const char *strShll, int numbSh)
{
	list_tShll *neew_hdSh;

	if (!heedSh)
		return (NULL);
	neew_hdSh = malloc(sizeof(list_tShll));
	if (!neew_hdSh)
		return (NULL);
	_memsetfnc((void *)neew_hdSh, 0, sizeof(list_tShll));
	neew_hdSh->numShll = numbSh;
	if (strShll)
	{
		neew_hdSh->stringShll = _strdupfnc(strShll);
		if (!neew_hdSh->stringShll)
		{
			free(neew_hdSh);
			return (NULL);
		}
	}
	neew_hdSh->nextShll = *heedSh;
	*heedSh = neew_hdSh;
	return (neew_hdSh);
}

/**
 * priintSh_lststr - Shows d strShll elmt of the lst
 * @hShll: ptr to 1st nodeeShll
 *
 * Return: sz of the lst
*/

size_t priintSh_lststr(const list_tShll *hShll)
{
        size_t ish;

	ish = 0;
        while (hShll)
        {
                _putsfnc(hShll->stringShll ? hShll->stringShll : "(nil)");
                _putsfnc("\n");
                hShll = hShll->nextShll;
                ish++;
        }
        return (ish);
}

/**
 * addiingnodSh_end - nodeeShll to d enth of d lst to be added
 * @heedSh: @ of ptr to the beginning of the nodeeShll
 * @strShll: fld of the nodeeShll
 * @numbSh: nodeeShll idxSh the will be used by hstry
 *
 * Return: sz of the lst
*/

list_tShll *addiingnodSh_end(list_tShll **heedSh,
		 const char *strShll, int numbSh)
{
	list_tShll *newSh_noodee, *nodeeShll;

	if (!heedSh)
		return (NULL);
	nodeeShll = *heedSh;
	newSh_noodee = malloc(sizeof(list_tShll));
	if (!newSh_noodee)
		return (NULL);
	_memsetfnc((void *)newSh_noodee, 0, sizeof(list_tShll));
	newSh_noodee->numShll = numbSh;
	if (strShll)
	{
		newSh_noodee->stringShll = _strdupfnc(strShll);
		if (!newSh_noodee->stringShll)
		{
			free(newSh_noodee);
			return (NULL);
		}
	}
	if (nodeeShll)
	{
		while (nodeeShll->nextShll)
			nodeeShll = nodeeShll->nextShll;
		nodeeShll->nextShll = newSh_noodee;
	}
	else
		*heedSh = newSh_noodee;
	return (newSh_noodee);
}

/**
 * free_listfnc - all nodeeShll nodes to be freed
 * @headSh_pointer: @ of the ptr to the 1st node of  nodeeShll
 *
 * Return: Nothing
*/

void free_listfnc(list_tShll **headSh_pointer)
{
        list_tShll *nodeeShll, *nxt_noodSh, *heedSh;

        if (!headSh_pointer || !*headSh_pointer)
                return;
        heedSh = *headSh_pointer;
        nodeeShll = heedSh;
        while (nodeeShll)
        {
                nxt_noodSh = nodeeShll->nextShll;
                free(nodeeShll->stringShll);
                free(nodeeShll);
                nodeeShll = nxt_noodSh;
        }
        *headSh_pointer = NULL;
}
