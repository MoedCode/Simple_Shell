
#include "main.h"

int Inter_Active()

{

	status = getline(&command, &getLine, stdin);
	if (status == -1)
		EXIT();
	/* "exit\n" == command =>0   !=>0   == 1 condation true*/
	if (!strcmp("exit\n", command))
	EXIT();
	cmd_args = tokenize(command, " \n");

	printDblArr(cmd_args,0);

	FreeVar(command);
	FreeArr(cmd_args);

	return (0);
}

