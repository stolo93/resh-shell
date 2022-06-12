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

    //the main loop of shell
    do {
		//print promt
		printf("%s @ %s -> ", getenv("USER"), getcwd(NULL, 0));

		//get input
		if (readLine(&line, &line_len, fin) == EOF){
			break;
		}

#ifdef DEBUG
	printf("line: %s_\n", line);
#endif

		//parse input
		parseArgs(line, &cur_program);

#ifdef DEBUG
	for (int i = 0; i < cur_program.args_count; i++){
		printf("ARG%d = %s\n", i, cur_program.args[i]);
	}
	printf("ending arg: %p\n", cur_program.args[cur_program.args_count]);
#endif

		//check for command and run it
		cmd_index = findBuiltin(cur_program.args[0]);
		if (cmd_index != -1){
			runBuiltin(cmd_index, cur_program.args);
			continue;
		}
		
		//or fork & exec
		executeProgram(&cur_program);

	} while(!exit);
	

	free(line);
	fclose(fin);
	return EXIT_SUCCESS;
}