#include "main.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Non_Inter_Ative()
{
	// printf("\n\n\n                   NON INTERACIVE Wait for the opening soon \n\n\n");
 // EHOSTUNREACH
	printf("None Interactive Tokenized Command Argunimts\n");

	while (1)
	{

		status = getline(&command, &getLine, stdin);
/*
		int tmp0 = strlen(command);
		char *tmp = malloc(tmp0 * sizeof(char));
		strcpy(tmp,command);
		tmp[tmp0-1] = '\0';
		printf("status [%i]getLine[%zu] cmd - [%s] \n ",status,getLine ,tmp);
		FreeVar(tmp);
*/
		if (status == -1)
			EXIT();

		// sleep(2);

		// printf("getline status %i  ", status); DEBUG("")

		if (command)
		{

		cmd_args = tokenize(command, " \n");
		if (cmd_args[0])
			Execute();
		}
		// printDblArr(cmd_args, 0);

	}
	return (0);
}
