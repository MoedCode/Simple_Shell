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
extern int status, pp_status,Execve, Exit_Status;
extern char *command ,**cmd_args,**Path_Array , *app_name;
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

size_t prin_argv(char **argv);
size_t printDblArr(char** DblArr, size_t NullTrm);
size_t  printInd(char *str, size_t len);
size_t print_ascii(char *str, size_t len);
size_t null_Terminate(char *string, char a, char b, size_t len);






/**/


int Inter_Active();
int Non_Inter_Ative();

char  **tokenize(char *cmd, char*  delim);
char **TokenEnvfPath();

int executeCommand(char *PATH);


 char *SearchIntEnv(char *startWith);

/*memory management*/
size_t freeDoubleArray(char **argv);

void if_Exit();

void FreeAll();
void EXIT();


/* befExe*/
char *isExecuteable();
int is_Multi_Cmd();
char *mrgCmdAndPath(char *currPath ,char *cmdName);
int  is_CorrectPath();
int Execute(void);



#endif
/*
Valgrind Full Flag
valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./hsh
*/