/*
 * Attack of the Alien Toilets - A space adventure!
 *
 * Author: Quinn Shultz
 * Contents: Helper functions to facilitate other modules.
 * Filename: misc.c
 */

#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

 //-----------------------------------------------------------------------------
 // NAME
 //      parse_object
 //
 // SYNOPSIS
 //      #include "misc.h"
 //
 //      OBJECT parse_object(noun);
 //
 // DESCRIPTION
 //
 //-----------------------------------------------------------------------------
OBJECT *parse_object(const char* noun)
{
    OBJECT* obj, * found = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (noun != NULL && strcmp(noun, obj->tag) == 0)
        {
            found = obj;
        }
    }
    return found;
}

//-----------------------------------------------------------------------------
 // NAME
 //      list_objects_at_location
 //
 // SYNOPSIS
 //      #include "misc.h"
 //
 //      int list_objects_at_location(location);
 //
 // DESCRIPTION
 //
 //-----------------------------------------------------------------------------
int list_objects_at_location(OBJECT* location)
{
    int count = 0;
    OBJECT* obj;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (obj != player && obj->location == location)
        {
            if (count++ == 0)
            {
                printf("You see:\n");
            }
            printf("%s\n", obj->description);
        }
    }
    return count;
}
