#ifndef MAIN_H
#define MAIN_H

/* Hraders*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/*      GLOBAL VARABLS */
extern size_t getLine ;
extern int status;
extern char *command ,**cmd_args , **PathArr;
//*appName = NULL;

/* MACROS */
#define DEBUG(M) printf("%s%s:%d\n", M, __FILE__, __LINE__);
#define FreeVar(var) do { \
    if (var) { \
        free(var); \
       var = NULL; \
    } \
} while(0)

#define FreeArr(arr) { \
    if (arr) { \
        freeDoubleArray(arr); \
        arr = NULL; \
    } \
} while(0)



/* Functions Prototype*/

/* String.c */

int Putchar(char c);
int printTS( char* s, size_t len);
char *StrCopy(char *dest, char *src);
int Strcmp(char *s1, char *s2);
size_t prin_argv(char **argv);
int printPathAtt(char** PathArr, char** argv);
size_t printDblArr(char** DblArr, size_t NullTrm);


/**/


int Inter_Active();
int Non_Inter_Ative();

char  **tokenize(char *cmd, char*  delim);
char **TokenEnvfPath();

int executeCommand(char *command, char **argv);

 char *SearchIntEnv(char *startWith);

/*memory management*/
size_t freeDoubleArray(char **argv);
void EXIT();


/* befExe*/
char *isExecuteable();
char *mrgCmdAndPath(char *currPath ,char *cmdName);
int Execute(void);



#endif
/*
Valgrind Full Flag
valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./hsh
*/