
#include "main.h"

int Inter_Active()

{
	write(STDIN_FILENO, "=> ", 3);

	status = getline(&command, &getLine, stdin);
	if (status == -1)
		EXIT();
	/* "exit\n" == command =>0   !=>0   == 1 condation true*/
	if (!strcmp("exit\n", command))
		EXIT();

	cmd_args = tokenize(command, " \n");
	// DEBUG(" ")

	printDblArr(cmd_args,0);
	if (cmd_args == NULL || cmd_args[0] == NULL)
	{
		// continue to the next iteration of the loop
		return 0; // or continue; if you're in a loop
	}
	// DEBUG(" Execute();")

	Execute();
	FreeVar(command);
	// DEBUG("FreeVar(command);  ")

	FreeArr(cmd_args);
	DEBUG("FreeArr(cmd_args); ")


	return (0);
}

