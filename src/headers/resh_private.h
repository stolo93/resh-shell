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

/**
 * @brief Specifiing type of IO redirection
 * 
 */
typedef enum redirection_t {NONE, PIPE, RIN, ROUT, RERROR} redirection_t;

/**
 * @brief Storing needed information about a program
 * 
 */
typedef struct _t {
    char ** args;
    size_t args_count;
    redirection_t redir;
    FILE * fin;
    FILE * fout;
} program_t;

/**
 * @brief Create default program_t variable
 * @p x Name of the variable 
 */
#define create_prog_info(x) program_t (x) = {.redir = NONE, .fin = stdin, .fout = stdout}

/**
 * @brief Readline from @p fin
 * Line does NOT contain new line character
 * 
 * @param lineptr Where to store the line
 * @param len 
 * @param fin 
 * @return Lenght of the line 
 */
size_t readLine(char ** lineptr, size_t * len, FILE * fin);

/**
 * @brief Parse the line given as @p line and store it as arguments int the @p prog_info.args
 * 
 * @param line Line containing program arguments
 * @param prog_info Destination for arguments
 * @return Number of arguments parsed
 */
int parseArgs(char * line, program_t * prog_info);

/**
 * @brief Get the type of IO rediretion wanted
 * 
 * @param line 
 * @return Type of IO redirection
 */
redirection_t getRedirType(char * line);




//---------PROGRAM EXECUTION------------

/**
 * @brief Fork and execute program @p prog_info 
 * Wait until program is ended and return it's shell return value
 * 
 * @param prog_info 
 * @return int 
 */
int executeProgram(program_t * prog_info);

#endif //_resh_PRIVATE_H