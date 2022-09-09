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
#include <string.h>

// #define DEBUG

int main(int argc, char ** argv)
{
	bool exit = false;
	char * line = NULL;
	size_t line_len = 0;
	FILE * fin = stdin;
	int cmd_index;

	create_prog_info(cur_program);

//---------The infinite loop of shell----------

    do {
		//print promt
		printf("%s @ %s -> ", getenv("USER"), getcwd(NULL, 0));

		//read input
		if (readLine(&line, &line_len, fin) == EOF){
			break;
		}

		//parse input into program arguments
		parseArgs(line, &cur_program);

		//check whether program is a command and if so run it
		cmd_index = findBuiltin(cur_program.args[0]);
		if (cmd_index != -1){
			runBuiltin(cmd_index, cur_program.args);
			continue;
		}
		
		//if program is not a command it is an executable, therefore fork & exec
		executeProgram(&cur_program);

	} while(!exit);
	

	free(line);
	fclose(fin);
	return EXIT_SUCCESS;
}