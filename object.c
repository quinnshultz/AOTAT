/*
 * Attack of the Alien Toilets - A space adventure!
 *
 * Author: Quinn Shultz
 * Contents: Items and persons!
 * Filename: object.c
 */

#include <stdio.h>
#include "object.h"

OBJECT objs[] = {
	{"a brightly lit airlock, tightly sealed against the darkness of space", "airlock", NULL},
	{"the armory, every light flickers noisily..." "armory", NULL},
	{"the barracks", "barracks", NULL},
	{"the bridge", "bridge", NULL},
	{"the cargo bay", "cargo", NULL},
	{"the lab", "lab", NULL},
	{"the medical bay", "medical", NULL},
	{"the mess hall", "mess", NULL},
	{"the darkness of space. You feel your last breath part your lips as you close your eyes...", "space", NULL},
	{"a silver coin", "silver", airlock},
	{"a gold coin", "gold", armory},
	{"a freakish alien", "alien", armory},
	{"yourself", "yourself", airlock}
};
