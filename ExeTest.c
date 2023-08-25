#include "main.h"
#include <stdio.h>
char *mrgCmdAndPath(char *currPath ,char *cmdName)
{

	size_t i, lnaloc =(strlen(cmdName) + strlen(currPath) + 2) ;
	char *mergedPath;


	mergedPath =malloc( lnaloc * sizeof(char) );
	if (!mergedPath)
		{
			fprintf(stderr, "mergedPath Allocation %s%d",__FILE__,__LINE__);
			return (NULL);
		}


	strcpy(mergedPath, currPath);
	strcat(mergedPath,"/");
	strcat(mergedPath,cmdName);


	if (access(mergedPath , X_OK)  == 0)
			return (mergedPath);
	free(mergedPath);


	// printf("\n>>>>>>>mergedPath<<<<< %s \n",mergedPath);

	return (NULL);

}
char *isExecuteable()
{
	size_t i = 0, j = 0,k = 0;

	char* isPathExe = NULL;
	Path_Array = TokenEnvfPath();


	while (Path_Array[j])
		j++;
	// printf("=> %zu",j);


	for (; i < j; i++)

			{
				char *isPathExe = mrgCmdAndPath(Path_Array[i], cmd_args[0]);
				// printf("{path [%s] cmd [%s]} %s :%i",Path_Array[i], cmd_args[0],__FILE__, __LINE__);
				k++;
				if (isPathExe)
					{
					FreeArr(Path_Array);
					return (isPathExe);
					}
			}

			// printf("k[%zu],j[%zu],%s%d\n",k,j,__FILE__,__LINE__);
	FreeArr(Path_Array);

	return (NULL);
}

