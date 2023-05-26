#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
ssize_t read_input(char **lineptr, size_t *n);
char **tokenize_input(char *line, const char *delim, int *num_tokens);
void free_arguments(char **args, int num_tokens);
void execmd(char **argv, char *path);
void print_env(char **envp);
void built_in_exit();
int main(int ac, char **argv, char **envp);





#endif
