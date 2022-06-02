/**
 * @file resh_input.c
 * @author Samuel Stolarik (xstola03@stud.fit.vutbr.cz)
 * @brief Input handling for resh shell
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "headers/resh_private.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ARG_LEN 128

size_t readLine(char ** lineptr, size_t * lenptr, FILE * fin)
{
    if (!lineptr || !lenptr || !fin) {return 0;}

    size_t char_count = getline(lineptr, lenptr, fin);
    if (char_count == -1){
        if (feof(fin)) {
            return EOF;
        }
        else {
            perror("Readline.");
            exit(EXIT_FAILURE);
        }        
    }

    //removing the newline character (otherwise it causes problems with execvp)
    char_count -= 1; 
    (*lineptr)[char_count] = '\0';

    return char_count;
}

redirection_t getRedirType(char * line)
{
    if (!line) {return RERROR;}

    char * c = strpbrk(line, "<>|");
    if (c == NULL){
        return RERROR;
    }

    switch (*c)
    {
        case '|':
            return PIPE;
            break;

        case '<':
            return RIN;
            break;
        
        case '>':
            return ROUT;
            break;

        default:
            return NONE;
            break;
    }
}

int parseArgs(char * line, program_t * prog_info)
{
    if (!line || !prog_info) {return 0;}
    
    //count number of arguments
    int arg_count = 0;
    char prev_char = ' ';
    
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (isspace(prev_char) && !isspace(line[i])){
            arg_count++;
        }

        prev_char = line[i];
    }

    prog_info->args_count = arg_count;

    prog_info->args = malloc(sizeof(char *) * (prog_info->args_count + 1)); //+1 to end the array with NULL


    //parsing arguments
    char * tmp = strtok(line, " ");
    int stored_args = 0;
    do {
        prog_info->args[stored_args++] = tmp; 


    } while ((tmp = strtok(NULL, " ")));
    
    prog_info->args[stored_args] = NULL;

    return prog_info->args_count;
}

