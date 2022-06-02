/**
 * @file resh_execute.c
 * @author Samuel Stolarik (stud.fit.vutbr.cz)
 * @brief Forking and executing of the resh shell
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "headers/resh.h"
#include "headers/resh_private.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

bool executeProgram(args_t * args)
{
    if (!args) {return false;}
    if (args->args == NULL || args->args_count <= 0) {return false;}

    pid_t p1 = fork();

    if (p1 == 0)
    {
        //child
        execvp(args->args[0], args->args);
    }
    else if (p1 == -1)
    {
        //error
        return false;
    }

    //parent
    wait(NULL);
    return true;
}