#include "main.h"
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
	char* isPathExe = NULL, **PathArray = TokenEnvfPath();

	while (PathArr[j])
		j++;

	for (; i < j; i++)

			{
				char *isPathExe = mrgCmdAndPath(PathArray[i], cmd_args[0]);
				k++;
				if (isPathExe)
					return (isPathExe);
			}
	FreeArr(PathArray);
			// printf("k[%zu],j[%zu],%s%d\n",k,j,__FILE__,__LINE__);

	return (NULL);
}

