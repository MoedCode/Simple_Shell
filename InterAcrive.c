
#include "main.h"

int Inter_Active()

{
	write(STDIN_FILENO, "$ ", 2);

	status = getline(&command, &getLine, stdin);
	if (status == -1)
		EXIT();
	/* "exit\n" == command =>0   !=>0   == 1 condation true*/
	if (!strcmp("exit\n", command))
		EXIT();

	cmd_args = tokenize(command, " \n");



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

