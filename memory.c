#include "main.h"

size_t freeDoubleArray(char **argv)
{
	size_t i, j;

	for (j = 0; argv[j]; j++)
			;
	for (i = 0; i < j; i++)
		if(argv[i])
		{

			free(argv[i]);
			argv[i] = NULL;
 		}



	if(argv)
	{
	free(argv);
	argv = NULL;
	}
	return (i);
}

void EXIT()
{
			FreeVar(command);
			FreeArr(cmd_args);
			FreeArr(PathArr);
			exit(127);
}