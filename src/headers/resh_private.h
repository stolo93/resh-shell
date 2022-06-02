/**
 * @file resh_readline.h
 * @author Samuel Stolarik (xstola03@stud.fit.vutbr.cz)
 * @brief Private API of resh shell
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _resh_PRIVATE_H
#define _resh_PRIVATE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//-----------INPUT HANDLING----------------

typedef enum redirection_t {NONE, PIPE, RIN, ROUT, RERROR} redirection_t;

typedef struct args_t {
    char ** args;
    size_t args_count;
    redirection_t redir;
    FILE * fin;
    FILE * fout;
} args_t;

#define create_args(x) args_t (x) = {.redir = NONE, .fin = stdin, .fout = stdout}

size_t readLine(char ** lineptr, size_t * len, FILE * fin);

redirection_t getRedirType(char * line);

int parseArgs(char * line, args_t * args);


//---------PROGRAM EXECUTION------------

bool executeProgram(args_t * args);

// bool connectFD(args_t * p1, args_t * p2, redirection_t redir);

#endif //_resh_PRIVATE_H