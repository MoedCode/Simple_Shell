#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
size_t printDblArr(char** DblArr, size_t NullTrm)
{
	size_t i, j;
	if (NullTrm >  0)
		j = NullTrm;
	else if (NullTrm == 0)
		for (j = 0; DblArr[j]; j++)
			if (DblArr[j] == NULL)
				return (0);

	for (i = 0; i < j; i++)
		printf("[%zu] - %s  \n", i,DblArr[i]);

	return (i);
}
size_t prin_argv(char **argv)
{
	size_t i,j;
	for (i = 0; argv[i]; i++)
		for (j = 0; argv[i][j] != '\0'; j++)
			putchar(argv[i][j]);
	return (j);
}

size_t  printInd(char *str, size_t len)
{
	size_t i = 0;
		while (i < len)
	{
		if (str[i] == '\0')
		{
			putchar('\\');
			putchar('0');
			i++;
		}
		if (str[i] == '\n')
		{
			putchar('\\');
			putchar('n');
			i++;
		}
		putchar(str[i]);
		i++;

	}
	putchar(10);

return (i);
}
size_t print_ascii(char *str, size_t len)
{
	size_t i;
	if (len == 0)
		len = strlen(str);
	if (!str)
	{
		printf("(null)\n");
		return (0);
	}
	for (i = 0; i < len; i++)
		printf(" %d",str[i]);
	putchar(10);

	return (i);
}

/**
 * null_Terminate - it replace char with another char
 * main purpose is termnationg string end with /n
 *
 * @string: to terminate
 * @a: char to pe replace
 * @b: char to replace with
 * @len:length of the string if greater than 0
 * if len = 0 function uses strlen
 * @return (size_t) number of itoration untill find
 */
size_t null_Terminate(char *string, char a, char b, size_t len)
{
	size_t i;
		if (len == 0)
			len = strlen(string);

	if (!string )
	{
		printf("(null)\n");
		return (0);
	}
	for (i = 0; i <= len; i++)
	{
		if (string[i] == a)
		{
				string[i] = b;
				return (i);
		}

	}
	printf("There ar no [%d] in given string\n",a);
	return (0);
}