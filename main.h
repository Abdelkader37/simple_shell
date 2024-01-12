#ifndef MAIN_H
#define MAIN_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define DELIMITER " \t\n"
extern char ** environ;

char *_strup(const char *str);
char *customReadInput(void);
size_t _strlen(const char *str);
int str_comp(char *s1, char *s2);
char* _strcpy(char* dest, const char* src);
char **stringTokenizer(char *input);
int countTokens(char *input);
char **tokenizeString(char *input, int tokenCount);
int execute_command(char **comnd,  char **argv, int idx);
char *_getenv(char *name);
char *path_search(char *cmd);
void freetool(char **arr);
void _perror(char *nm, char *cmd, int i);
void reverse(char *s, int len);
char* int_to_str(int n);
int _absolut(char *str) ;
void _perror(char *nm, char *cmd, int i);
void put_env(char **cmd,int *status);
void _break(char**input, char **argv, int *status, int i) ;
void input_built(char **input, char **argv, int *status, int i);
int non_input(char *cmd);
int int_to_str2(char *str);
char *search_in_path(char *cmd, char *_path);

#endif
