#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define TOKENS 100

extern char **environ;

/* header files */

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <dirent.h>

/* prototypes */

extern ssize_t getline(char **__restrict __lineptr, size_t *n, FILE *stream);
extern int isatty(int __fd) __THROW;
extern int unsetenv(const char *__name) __THROW __nonnull((1));
extern int setenv(const char *__name, const char *__value, int __replace);
extern void exit(int __status) __THROW __attribute__ ((__noreturn__));
extern int execvp(const char *__file, char *const __argv[]);
extern void free(void *__ptr) __THROW;

void prompt(void);
int main(int argc, char *argv[], char *envp[]);
void main_l(char *envp[]);
void execve_func(char **args, char *const env[]);
int _strcmp(const char *d1, const char *d2);
char *_strcat(char *d, const char *s);
int _setenv(char *name, char *value);
int env_main(void);
int _unsetenv(char *name);
char *_strcpy(char *dest, char *src);
void exec_build_cmd(char **args);
int _atoi(const char *s);
void handle_my_exit(char *status);
char *get_path(const char *command);
int my_cd(char *path);
char *_strdup(const char *st);
size_t _strlen(const char *s);
char *_getenv(char *name);
void free_tokens(char **tokens);
void exec_build_cmd(char **args);
void exec_cd(char **args);
char **tokenize(char **input, const char *delim);
void my_env(char *name[]);
void my_exit(const char *const args[]);


#endif
