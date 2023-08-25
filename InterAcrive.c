
#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Inter_Active()

{

	write(STDIN_FILENO, "$ ", 2);

	status = getline(&command, &getLine, stdin);
	if (status == -1)
		EXIT();
/*
	printf("command => %s\n", command);


	size_t i, j,k ,  comLn =  strlen(command);

	char *comPort2 = malloc(comLn * sizeof(char *));

	for( i = 0; i < comLn ; i++)
	{
		putchar(command[i]); DEBUG("")
		for (j = i ; j < comLn; j++, k++)
		{
		 DEBUG("");
			comPort2[k] = command[j];
		}
	}

	printf("second portion of command => %s", comPort2);
	FreeVar(comPort2);
	*/
	/* "exit\n" == command =>0   !=>0   == 1 condation true*/


	cmd_args = tokenize(command, " \n");
	int exit1, exit2;
	exit1 = !strcmp("exit\n", cmd_args[0]);
	exit2 = !strcmp("exit", cmd_args[0]);

	if ( exit1 || exit2)
	{
		if (cmd_args[1])
		{	int i;
				for (i = 0; cmd_args[1][i] != '\0'; i++)
				{
					if (!((cmd_args[1][i] - 48) >= 0 && (cmd_args[1][i] - 48) <= 9))
					{
						EXIT();
					}
				}
			Exit_Status = atoi(cmd_args[1]);
		}
		EXIT();
	}


	if (cmd_args == NULL || cmd_args[0] == NULL)
	{
		// continue to the next iteration of the loop
		return 0; // or continue; if you're in a loop
	}


	Execute();

	FreeVar(command);

	FreeArr(cmd_args);
	return (0);
}

