/*
 * Attack of the Alien Toilets - A really fucked up game
 *
 * Author: Quinn Shultz
 * Contents: Macro definitions and function prototypes used by aotat
 * Filename: aotat.h
 */

#ifndef AOTAT
#define AOTAT

/* Macro definitions */
#define BUFSIZE 256
#define MAXLINE 4096

/* Global variables */
char *buff;

/* Function prototypes */
void exit_aotat(void);
static int parse_and_execute(void);
static int get_input(void);
#endif
