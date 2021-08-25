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
	printf("\n\n\tWelcome to: Attack of the Alien Toilets!\n\n");
	printf("\tChoose your weapon:\n");

	while (get_input() && parse_and_execute());

	printf("Goodbye!\n");
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
	char *noun = strtok(buff, " \n");

	if (verb != NULL)
	{
		if (strcmp(verb, "quit") == 0)
		{
			exit_aotat();
		}
		else if (strcmp(verb, "look") == 0)
		{
			printf("It's too dark to see.\n");
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
	free(buff);			// Deallocate memory for buffer
	exit(0);
}
