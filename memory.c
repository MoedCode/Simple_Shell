#include "main.h"

size_t freeDoubleArray(char **argv)
{
	size_t i, j;

	for (j = 0; argv[j]; j++)
			;
	for (i = 0; i <= j; i++)
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
void if_Exit()
{
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
}
void EXIT()
{
			FreeVar(command);
			FreeArr(cmd_args);
			FreeArr(Path_Array);
			exit(Exit_Status);
}
void FreeAll()
{
			FreeVar(command);
			FreeArr(cmd_args);
			FreeArr(Path_Array);

}