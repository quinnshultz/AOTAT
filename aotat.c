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

	// Allow user input until end of buffer
	while (fgets(buff, BUFSIZE, stdin) != NULL) {
		// Replace newline with NUL
		buff[strlen(buff) -1] = '\0';

		// User typed the exit command
		if (buff == "exit") {
			exit_aotat();
		}
	}
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
