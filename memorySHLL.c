#include "shell.h"
/* CREATED BY Amina El Hakik, Mehdi Belaazri */

/**
 * bufferfreeeSh - the ptr to be freed (and its @)
 * @pointSh_er: @ of d ptr to be freed
 *
 * Return: 1 (Success), 0 (Failure).
*/

int bufferfreeeSh(void **pointSh_er)
{
	if (pointSh_er && *pointSh_er)
	{
		free(*pointSh_er);
		*pointSh_er = NULL;
		return (1);
	}
	return (0);
}

