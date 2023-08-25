#include "main.h"
#include <stdio.h>
#include <stdlib.h>


 char *SearchIntEnv(char *startWith)
{
	extern char **environ;
	char **s = environ;

	for (; *s; s++ )
	/* && s[i][5] != '\0' && s[i][5] != ' ' */
		if (!strncmp(startWith, *s, 5 ) )
		{

			return (*s);
		}

return (NULL);
}
/**
 * @brief
 *
 * @return char**
 */
char **TokenEnvfPath()
{
	size_t i, j;
	/* copy the Enviroment path  antoher string so we doont tokenize the system path*/

	char* envPath = strdup(SearchIntEnv("PATH="));
	if (!envPath )
	{

		DEBUG(" (null envPath ")
		EXIT();
		return (NULL);
	}
	else {


	}
	/* inctrement the string pointer which store the  path copy py 5 (0 -> 4)  to strart point the charcter after "PATH="   */



	char **Array = tokenize(envPath, ":=");
	FreeVar(envPath);



	return (Array);
}