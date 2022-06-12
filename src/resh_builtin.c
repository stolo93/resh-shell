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

#define NOT_FOUND -1

/**
 * @brief Array of built-in functions names
 * 
 */
char * builtin_names[] = {

};

/**
 * @brief Array of built-in functions
 * 
 */
int (*builtin_fns[])(char **) = {

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



