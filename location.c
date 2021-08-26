/*
 * Attack of the Alien Toilets - A space adventure!
 *
 * Author: Quinn Shultz
 * Contents: Verb functions.
 * Filename: location.c
 */

#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

//-----------------------------------------------------------------------------
// NAME
//      execute_look
//
// SYNOPSIS
//      #include "location.h"
//
//      void execute_look(noun);
//
// DESCRIPTION
//      What to do if the user types the "look" verb.
//-----------------------------------------------------------------------------
void execute_look(const char* noun)
{
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You are in %s.\n", player->location->description);
        list_objects_at_location(player->location);
    }
    else
    {
        printf("I don't understand what you want to see.\n");
    }
}

//-----------------------------------------------------------------------------
// NAME
//      execute_go
//
// SYNOPSIS
//      #include "location.h"
//
//      void execute_go(noun);
//
// DESCRIPTION
//      What to do if the user types the "go" verb.
//-----------------------------------------------------------------------------
void execute_go(const char* noun)
{
    OBJECT* obj = parse_object(noun);
    if (obj == NULL)
    {
        printf("I don't understand where you want to go.\n");
    }
    else if (obj == player->location)
    {
        printf("You are already there.\n");
    }
    else
    {
        printf("OK.\n");
        player->location = obj;
        execute_look("around");
    }
}
