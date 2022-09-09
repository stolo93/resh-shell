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

int executeProgram(program_t * prog_info)
{
    if (!prog_info) {return false;}
    if (prog_info->args == NULL || prog_info->args_count <= 0) {return false;}

    pid_t p1 = fork();

    if (p1 == 0)
    {
        //child
        execvp(prog_info->args[0], prog_info->args);
        //exec only returns in case of error
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    else if (p1 == -1)
    {
        //error
        return false;
    }

    //parent
    int stat;
    waitpid(p1, &stat, 0);
    
    if (stat == 0){
        return 0; //child process ended correctly
    }

    else {
        return WEXITSTATUS(stat); //return value of the child proces
    }
}
