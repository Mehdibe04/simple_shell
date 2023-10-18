#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READING_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLSH -1

#define CMD_NORM_CHAINING	0
#define CMD_OR_CHAINING		1
#define CMD_AND_CHAINING	2
#define CMD_CHAIN_CHAINING	3

#define CNVRT_LOWERCASE	1
#define CNVRT_UNSIGNED	2

#define USING_getlinefnc 0

#define HIST_FILE_SHLL	".simple_shell_history"
#define HIST_MAX_SHLL	4096

extern char **environ;


/**
 * struct liststrShll - singly linked list
 * @numShll: the field's num
 * @stringShll: str input
 * @next:  ptr 2 d nxt nodeeShll
*/

typedef struct liststrShll
{
	int numShll;
	char *stringShll;
	struct liststrShll *nextShll;
} list_tShll;

/**
 *struct passinfShll - psdo-args to pass in2 func
 *@arg: getline generating an str that contains args
 *@argv: list of args
 *@pathShll: curr cmd's path
 *@argc: numb of args
 *@line_cntShll: the err's cnt
 *@errr_numbShll: err coode 4 exit_sShll
 *@linecnt_flgShll: liine of 2
 *@fnameShll: d prog fname
 *@envirShll: linked_lst @
 *@environ: cpy of environ from the envir
 *@histShll: nodeeShll's hist
 *@aliiasShell: nodeeShll's alias
 *@env_chgedShll: 1 if environ chngd
 *@statuusShll: stat of lst_exe_cmd
 *@cmd_buffShell: @ of ptr to cmd_buffer
 *@cmd_buff_typeShell: CMD_type
 *@read2fdShll: the fddSh 2 read from
 *@historycountSh: line's hist num cnt
*/

typedef struct passinfShll
{
	char *arg;
	char **argv;
	char *pathShll;
	int argc;
	unsigned int line_cntShll;
	int errr_numbShll;
	int linecnt_flgShll;
	char *fnameShll;
	list_tShll *envirShll;
	list_tShll *histShll;
	list_tShll *aliiasShell;
	char **environ;
	int env_chgedShll;
	int statuusShll;
	char **cmd_buffShell;
	int cmd_buff_typeShell;
	int read2fdShll;
	int historycountSh;
} info_to_structShll;

#define INIT_CASE \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contns builtin str
 *@typeShll: b8ltin cmd flg
 *@fctShll: func
*/

typedef struct builtin
{
	char *typeShll;
	int (*fctShll)(info_to_structShll *);
} builtinTblShll;


int hsh(info_to_structShll *, char **);
int findSh_builtinfnc(info_to_structShll *);
void findSh_comanddfnc(info_to_structShll *);
void forkSh_comaandfnc(info_to_structShll *);

int isSh_comandfnc(info_to_structShll *, char *);
char *duplicateSh_charssfnc(char *, int, int);
char *findiingSh_patthfnc(info_to_structShll *, char *, char *);

int loopphshfnc(char **);

void _eputsfnc(char *);
int _eputcharfnc(char);
int _putfdfnc(char cShll, int fddSh);
int _putsfncfdfnc(char *string, int fddSh);

int _strlenfnc(char *);
int _strcmpfnc(char *, char *);
char *startsSh_witthfnc(const char *, const char *);
char *_strcatfnc(char *, char *);

char *_strcpyfnc(char *, char *);
char *_strdupfnc(const char *);
void _putsfnc(char *);
int _putcharfnc(char);

char *_strncpyfnc(char *, char *, int);
char *_strncatfnc(char *, char *, int);
char *_strchrfnc(char *, char);

char **strtoowsSh(char *, char *);
char **strtoowsSh2(char *, char);

char *_memsetfnc(char *, char, unsigned int);
void fiilefreeeSh(char **);
void *_reallocfnc(void *, unsigned int, unsigned int);

int bufferfreeeSh(void **);

int iintrctvSh(info_to_structShll *);
int deliimfnc(char, char *);
int _isalphafnc(int);
int _atoifnc(char *);

int _erratoifnc(char *);
void priintSh_errrfnc(info_to_structShll *, char *);
int printSh_ddfnc(int, int);
char *convrt_numbfnc(long int, int, int);
void removeeSh_cmmtsfnc(char *);

int _myexitfnc(info_to_structShll *);
int _mycdfnc(info_to_structShll *);
int _myhelpfnc(info_to_structShll *);

int _myhistoryfnc(info_to_structShll *);
int _myaliasfnc(info_to_structShll *);

ssize_t gettSh_inptfnc(info_to_structShll *);
int _getlinefnc(info_to_structShll *, char **, size_t *);
void sigiintShhandlerfnc(int);

void clear_info_fnc_shll(info_to_structShll *);
void setSh_iinfofnc(info_to_structShll *, char **);
void freeSh_iinfofnc(info_to_structShll *, int);

char *_getenvfnc(info_to_structShll *, const char *);
int _myenvfnc(info_to_structShll *);
int _mysetenvfnc(info_to_structShll *);
int _myShunsetenvfnc(info_to_structShll *);
int populateSh_envir_lstfnc(info_to_structShll *);

char **getSh_enviironfnc(info_to_structShll *);
int _unsetenvfnc(info_to_structShll *, char *);
int _setenvfnc(info_to_structShll *, char *, char *);

char *get_hstry_fnc(info_to_structShll *infShll);
int wriite_hstoryfnc(info_to_structShll *infShll);
int readSh_hstoryfnc(info_to_structShll *infShll);
int buiildSh_hstory_lstfnc(info_to_structShll *infShll, char *bufferSh, int linecntSh);
int renumbrSh_hstoryfnc(info_to_structShll *infShll);

list_tShll *addiingnodSh(list_tShll **, const char *, int);
list_tShll *addiingnodSh_end(list_tShll **, const char *, int);
size_t priintSh_lststr(const list_tShll *);
int deleteSh_nodat_indxfnc(list_tShll **, unsigned int);
void free_listfnc(list_tShll **);

size_t list_len_fnc(const list_tShll *);
char **list_tShllo_strings_SHLL_fnc(list_tShll *);
size_t priintSh_liistSh(const list_tShll *);
list_tShll *nodstartssSh(list_tShll *, char *, char);
ssize_t nod_iindexSh(list_tShll *, list_tShll *);

int iisChaiinSh(info_to_structShll *, char *, size_t *);
void check_chain_fnc_shll(info_to_structShll *, char *, size_t *, size_t, size_t);
int replace_alias_fnc_shll(info_to_structShll *);
int replace_vars_fnc_shll(info_to_structShll *);
int replace_string_fnc_shll(char **, char *);

#endif

