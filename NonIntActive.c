#include "main.h"
#include <errno.h>
#include <stdio.h>
int Non_Inter_Ative()
{
	printf("\n\n\n                   NON INTERACIVE Wait for the opening soon \n\n\n");
 // EHOSTUNREACH
	while (1)
	{
		status = getline(&command, &getLine, stdin);
		if (status == -1)
			EXIT();
		if (!command || !cmd_args)
				fprintf(stderr, "(NULL)%s :%i\n",__FILE__,__LINE__);

		cmd_args = tokenize(command, " \n");
		printDblArr(cmd_args, 0);

	}
	return (0);
}
