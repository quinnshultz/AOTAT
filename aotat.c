/*
 * Attack of the Alien Toilets - A space adventure!
 *
 * Author: Quinn Shultz
 * Contents: Main function and user input processing functions
 * Filename: aotat.c
 */

#include <string.h>
#include <stdio.h>
#include "location.h"

// User-input buffer
static char buff[100];

//-----------------------------------------------------------------------------
// NAME
//      get_input
//
// SYNOPSIS
//      #include "aotat.h"
//
//      int get_input();
//
// DESCRIPTION
//
//-----------------------------------------------------------------------------
static int get_input()
{
	printf("\n--> ");
	return fgets(buff, sizeof(buff), stdin) != NULL;
}

//-----------------------------------------------------------------------------
// NAME
//      parse_and_execute
//
// SYNOPSIS
//      #include "aotat.h"
//
//      int parse_and_execute();
//
// DESCRIPTION
//
//-----------------------------------------------------------------------------
static int parse_and_execute()
{
	char *verb = strtok(buff, " \n");
	char *noun = strtok(NULL, " \n");

	if (verb != NULL)
	{
		if (strcmp(verb, "quit") == 0)
		{
			printf("Goodbye!\n");
			return 0;
		}
		else if (strcmp(verb, "look") == 0)
		{
			execute_look(noun);
		}
		else if (strcmp(verb, "go") == 0)
		{
			execute_go(noun);
		}
		else
		{
			printf("I don't know how to '%s'.\n", verb);
		}
	}
	return 1;
}

//-----------------------------------------------------------------------------
// NAME
//	main, main function, aotat
//
// SYNOPSIS
//	#include "aotat.h"
//
//	int main();
//
// DESCRIPTION
// 	Gets user input, prints some arbitrary text
//-----------------------------------------------------------------------------
int main(void)
{
	// Print welcome message
	printf("Welcome to: Attack of the Alien Toilets!\n");
	execute_look("around");

	while (get_input() && parse_and_execute());

	printf("Goodbye!\n");
	return 0;
}
