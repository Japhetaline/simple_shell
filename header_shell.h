#ifndef _HEADER_SHELL_
#define _HEADER_SHELL_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * shell_start
 */

int main(int argc, char **argv, char **envp);
void shell_swift(void);
void operate(int indicators);
void _EOF(char *barrier);
void exit_shell(char **instruct);

/*
 * free_store
 */

void free_mem(char **instruct);
void free_exit(char **instruct);

/*
 * tokening
 */
char **tokening(char *barrier, const char *t);
#endif /*_HEADER_SHELL_*/
