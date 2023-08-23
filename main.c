#include "main.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
/*
Docker >> inveromint for build and run apps outside of opration system
*/
 size_t getLine = 0;
 int status, interActicve;
 char *command = NULL,**cmd_args = NULL;
int main( int argc, char **argv)
{

	int interActicve = isatty(STDIN_FILENO);
	if( interActicve)
	{
			while(1)
		{
			Inter_Active();
		}
	}
	else
	{
		Non_Inter_Ative();

	}

	return (0);
}
