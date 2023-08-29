#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
int  freeStrVar(char *str)
{
    if(str)
    {
        free(str);
        str =NULL;
        return (0);
    }
return (1);
}
int main(int argc , char *argv[])
{
    size_t cmdgtlnLen;
    int getLineReturn;
    char *command;

    while (1)
    {
       write(STDIN_FILENO, "$ ", 2);

       getLineReturn =  getline(&command , &cmdgtlnLen, stdin);

       if (getLineReturn == -1 || !strcmp("exit\n", command))
       {
           freeStrVar(command);
           exit(0);
       }

        printf("command => %s", command);
        // freeStrVar(command);


    }
}