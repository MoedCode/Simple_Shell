#include "main.h"

int  Execute(void)
{
	char *exePath = NULL, **PathArray = NULL;

	if (!strcmp("ENV", cmd_args[0]))
		{

			char **PathArray = TokenEnvfPath();

			// }

			printDblArr(PathArray, 0);
			DEBUG("printDblArr(PathArr, 0); ")

			FreeArr(PathArray);
			DEBUG("FreeArr(PathArr);")

		}
	DEBUG(" exePath = isExecuteable();");
	// exePath = isExecuteable();
	printf(":: Executable Path is >> %s %s :%i",exePath , __FILE__,__LINE__);

	return (0);

}