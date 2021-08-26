/*
 * Attack of the Alien Toilets - A space adventure!
 *
 * Author: Quinn Shultz
 * Contents: Items and persons!
 * Filename: object.h
 */

typedef struct object {
   const char    *description;
   const char    *tag;
   struct object *location;
} OBJECT;

extern OBJECT objs[];

#define airlock (objs + 0)
#define armory (objs + 1)
#define barracks (objs + 2)
#define bridge (objs + 3)
#define cargo (objs + 4)
#define lab (objs + 5)
#define medical (objs + 6)
#define mess (objs + 7)
#define space (objs + 8)
#define silver (objs + 9)
#define gold       (objs + 10)
#define alien      (objs + 11)
#define player     (objs + 12)

#define endOfObjs  (objs + 13)
