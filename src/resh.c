/**
 * @file resh.c
 * @author Samuel Stolarik (xstola03@stud.fit.vutbr.cz)
 * @brief Main C file of the new resh shell
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "headers/resh_private.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define DEBUG

int main(int argc, char ** argv)
{
	bool exit = false;
	char * line = NULL;
	size_t line_len = 0;
	FILE * fin = stdin;

	create_args(cur_arguments);

    //the main loop of shell
	//TODO problem with eof
    do {
		//print promt
		printf("%s @ %s -> ", getenv("USER"), getcwd(NULL, 0));

		//get input
		if (readLine(&line, &line_len, fin) == EOF){
			exit = true;
		}

		//parse input
		parseArgs(line, &cur_arguments);

		//check for command and run it
		
		//or fork & exec
		if (!executeProgram(&cur_arguments)) {
			exit = true;
		}

	} while(!exit);

	return EXIT_SUCCESS;
}