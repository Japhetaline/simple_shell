#ifndef _HEADER_SHELL_
#define _HEADER_SHELL_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/** shell_start */

int main(int argc, char **argv, char **env);
void shell_swift(void);
void operate(int indicators);
void _EOF(char *barrier);
void exit_shell(char **instruct);

/* free_store */

void free_mem(char **instruct);
void free_exit(char **instruct);

/*tokening*/
char **tokening(char *barrier, const char *t);

/* support_func */
int _strcp(char *k1, char *k2);
unsigned int _strlen(char *k);
char *_strcat(char *terminus, char *origin);
char *_strcopy(char *destination, char *source);
int _atoi(char *k);

/* shell_execute */
void enforce(char **instruct, char *name, char **env, int spiral);
void proof_env(char **env);
char **_getROUTE(char **env);
void msg_error(char *name, int spinal, char **instruct);

/* procreate */
void procreate(char **instruct, char *name, char **env, int spiral);
int change_dr(const char *trail);
#endif /*_HEADER_SHELL_*/
