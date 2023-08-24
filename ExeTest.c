#include "main.h"
#include <stdio.h>
char *mrgCmdAndPath(char *currPath ,char *cmdName)
{
	DEBUG(" ")
	size_t i, lnaloc =(strlen(cmdName) + strlen(currPath) + 2) ;
	char *mergedPath;
	DEBUG(" ")

	mergedPath =malloc( lnaloc * sizeof(char) );
	if (!mergedPath)
		{
			fprintf(stderr, "mergedPath Allocation %s%d",__FILE__,__LINE__);
			return (NULL);
		}
	DEBUG(" ")

	strcpy(mergedPath, currPath);
	strcat(mergedPath,"/");
	strcat(mergedPath,cmdName);
	DEBUG(" ")

	if (access(mergedPath , X_OK)  == 0)
			return (mergedPath);
	free(mergedPath);
	DEBUG(" ")

	// printf("\n>>>>>>>mergedPath<<<<< %s \n",mergedPath);

	return (NULL);

}
char *isExecuteable()
{
	size_t i = 0, j = 0,k = 0;
	DEBUG(" ")
	char* isPathExe = NULL, **PathArray = TokenEnvfPath();
	DEBUG(" ")

	while (PathArray[j])
		j++;
	printf("=> %zu",j);
	DEBUG(" ")

	for (; i < j; i++)

			{
				char *isPathExe = mrgCmdAndPath(PathArray[i], cmd_args[0]);
				printf("{path [%s] cmd [%s]} %s :%i",PathArray[i], cmd_args[0],__FILE__, __LINE__);
				k++;
				if (isPathExe)
					{
					FreeArr(PathArray);
					return (isPathExe);
					}
			}

			// printf("k[%zu],j[%zu],%s%d\n",k,j,__FILE__,__LINE__);
	FreeArr(PathArray);

	return (NULL);
}

