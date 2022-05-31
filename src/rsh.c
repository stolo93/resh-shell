/**
 * @file rsh.c
 * @author Samuel Stolarik (xstola03@stud.fit.vutbr.cz)
 * @brief Main C file of the new rsh shell
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	bool exit = false;
	char * line = NULL;
	int line_len = 0;
	FILE * fin = stdin;

    //the main loop of shell
    do {
		//get input
		
		//parse input

		//check for command

		//run command or fork & exec
	} while(!exit);

	return EXIT_SUCCESS;
}