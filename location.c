/*
 * Attack of the Alien Toilets - A really fucked up game
 *
 * Author: Quinn Shultz
 * Contents: Location structures, look and go functions
 * Filename: location.c
 */

#include <stdio.h>
#include <string.h>

struct location {
	const char *description;
	const char *tag;
}
locs[] = {
	{"an open field", "field"},
	{"a little cave", "cave"}
};

#define numberOfLocations (sizeof(locs) / sizeof(*locs))

static unsigned locationOfPlayer = 0;

void execute_look(const char *noun)
{
	if (noun != NULL && strcmp(noun, "around") == 0)
	{
		printf("You are in %s.\n", locs[locationOfPlayer].description);
	}
	else
	{
		printf("I don't understand what you want to see.\n");
	}
}

void execute_go(const char *noun)
{
	unsigned i;
	for (i = 0; i < numberOfLocations; i++)
	{
		if (noun != NULL && strcmp(noun, locs[i].tag) == 0)
		{
			if(i == locationOfPlayer)
			{
				printf("You are already there.\n");
			}
			else
			{
				printf("OK.\n");
				locationOfPlayer = i;
				execute_look("around");
			}
			return;
		}
	}
	printf("I don't understand where you want to go.\n");
}
