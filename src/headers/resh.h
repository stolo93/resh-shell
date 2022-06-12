/**
 * @file resh.h
 * @author Samuel Stolarik (stud.fit.vutbr.cz)
 * @brief resh shell API
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _resh_H
#define _resh_h


//BUILTIN FUNCTIONS

int resh_help(char **);

int resh_exit(char **);

int resh_cd(char **);

#endif //_resh_H