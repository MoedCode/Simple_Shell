#include "main.h"
#include <stdlib.h>

 int pp_status, Execve;
	extern char **environ;
int executeCommand(char *PATH)
{
	/* if (!strcmp(command , "env"))
	 	 return(0); */
	pid_t pid;
	// int status;

	pid = fork();

	if (pid == 0) {
		// Child process
		Execve = execve(PATH, cmd_args,NULL);
		if (Execve == -1)
		{

			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &pp_status, 0);
		if (WIFEXITED(pp_status))
		{
			int tmpExSt = WIFEXITED(pp_status);
			return (tmpExSt);
		}



	}
	else
	{
		return (-1);
	}

	return 0;
}
int  Execute(void)
{
	int execve_status = 0;
	char *exePath = NULL, **PathArray = NULL;

	if (!strcmp("ENV", cmd_args[0]))
		{
			char **PathArray = TokenEnvfPath();
			printDblArr(PathArray, 0);
			FreeArr(PathArray);
		}

	// DEBUG(" exePath = isExecuteable();");
	exePath = isExecuteable();
	if (exePath)
	{
	execve_status = executeCommand(exePath);

	FreeVar(exePath);
	// FreeAll();
	}
	else{

		printf("%s: 1: %s: not found\n",app_name, cmd_args[0]);
		return (127);
	}
	return (execve_status);
}