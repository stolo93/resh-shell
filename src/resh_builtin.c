/**
 * @file resh_bultin.c
 * @author your name (xstola03@stud.fit.vutbr.cz)
 * @brief Module with shell built-in commands
 * @version 0.2
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "headers/resh.h"
#include "headers/resh_private.h"

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

/**
 * @brief Array of built-in functions names
 * 
 */
char * builtin_names[] = {
    "help",
    "exit",
    "cd",
};

/**
 * @brief Array of built-in functions
 * 
 */
int (*builtin_fns[])(char **) = {
    resh_help,
    resh_exit,
    resh_cd,
};


int builtinLenght()
{
    return sizeof(builtin_names) / sizeof(char *);
}


int findBuiltin(char * name)
{
    if (!name) {return NOT_FOUND;}
    int lenght = builtinLenght();

    for (int i = 0; i < lenght; i++){
        if (strcmp(builtin_names[i], name) == 0){
            return i;
        }
    }  

    return NOT_FOUND;
}

int runBuiltin(int index, char ** args)
{
    if (index == -1){return 0;}

    return builtin_fns[index](args);
}


//--------BUILT-IN FUNCTIONS--------

int resh_help(char ** args)
{    printf("Resh shell\nBuilt just as a experiment.\nType in a command and hit enter to run it.\nTo exit the shell either use \"exit\" or CTRL+D.\n\nList of built-in commands:\n");
    
    int lenght = builtinLenght();

    for (int i = 0; i < lenght; i++){
        printf("\t- %s\n", builtin_names[i]);
    }

    return 0;
}

int resh_exit(char ** args)
{
    exit(EXIT_SUCCESS);
}

int resh_cd(char ** args)
{
    char * dir;
    if (args[1] == NULL){
        dir = getenv("HOME");
    }
    else if (strcmp(args[1], "~") == 0){
        dir = getenv("HOME");
    }
    else {
        dir = args[1];
    }


    if (chdir(dir) == -1){
        perror(NULL);
        return 1;
    }
    
    return 0;
}
