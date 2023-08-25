#include "main.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
/*
Docker >> inveromint for build and run apps outside of opration system
*/
 size_t getLine = 0;
 int status, interActicve, Exit_Status;
 char *command = NULL,**cmd_args = NULL ,**Path_Array = NULL, *app_name = NULL;
int main( int argc, char **argv)
{
	app_name = argv[0];
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
