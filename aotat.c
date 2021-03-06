/*
 * Attack of the Alien Toilets - A really fucked up game
 *
 * Author: Quinn Shultz
 * Contents: Main function and user input processing functions
 * Filename: aotat.c
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "aotat.h"

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
	// Allocate memory for user-input buffer
	buff = (char *) malloc(sizeof(char)*BUFSIZE);

	// Print welcome message
	printf("Welcome to: Attack of the Alien Toilets!\n");
	printf("It's very dark in here.\n");

	while (get_input() && parse_and_execute());

	exit_aotat();
}

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
	return fgets(buff, BUFSIZE, stdin) != NULL;
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
			exit_aotat();
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
//	exit_aotat
//
// SYNOPSIS
//	#include "aotat.h"
//
//	void exit_aotat();
//
// DESCRIPTION
// 	Frees any remaining data structures and closes the game.
//-----------------------------------------------------------------------------
void exit_aotat(void) {
	// Deallocate memory for buffer
	free(buff);
	
	printf("Goodbye!\n");
	exit(0);
}
