/**
 * @file resh_signals.c
 * @author Samuel Stolarik (xstola03@stud.fit.vutbr.cz)
 * @brief ignal handlers
 * @version 0.2
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "headers/resh.h"
#include "headers/resh_private.h"

#include <stdarg.h>
#include <signal.h>

void ignoreSignals(int sig_count, ...)
{
    va_list sig_list;

    va_start(sig_list, sig_count);

    for (int i = 0; i < sig_count; i++){
        signal(va_arg(sig_list, int), SIG_IGN);
    }    

    va_end(sig_list);

    return;
}

void resetSignals(int sig_count, ...)
{
    va_list sig_list;

    va_start(sig_list, sig_count);

    for (int i = 0; i < sig_count; i++){
        signal(va_arg(sig_list, int), SIG_DFL);
    }    

    va_end(sig_list);

    return;
}
