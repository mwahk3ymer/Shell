#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

extern char **environ;
void prompt(void);
int builtin(const char *str);
void exits_sh(char, **tokens);
int execmd(char, **tokens, char *args);
int main(int ac, char *argv[]);
void printenv(void);
char *read_input(void);
void _puts(char *str);
size_t _stringlength(const char *s);
char *_stringconcat(char *dest, const char *src);
unsigned int _white_space(const char *s);
char **_strto_tokens(const char *str);
int exec_path(char **tokens, char *path, char *args);
int check_path(char *s);
char *path_builder(char **tokens);

#endif
