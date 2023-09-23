#ifndef _SHELL_H
#define _SHELL_H
/** all includes **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
/** external vars **/
extern char **environ; /*environ*/
extern char *cmd_line; /*line*/
extern char **parsed_cmds; /*commands*/
extern char *prompt; /*shell_name*/
extern int status; /*status*/
/** constants **/
#define HANDLE_INT_CMD 2
#define HANDLE_EXT_CMD 1
#define HANDLE_PATH 3
#define HANDLE_INVALID_CMD -1
/** function prototypes **/
void custom_printf(char *, int);
void remove_newline_character(char *);
int _strlen(char *);
char *cutomized_strtok_for_shell(char *, char *, char **);
char **token_processor(char *, char *);
void quit(char **);
void env(char **);
char *_strcat(char *, char *);
char *_strchr(char *, char);
int _strspn(char *, char *);
void _strcpy(char *, char *);
int _strcmp(char *, char *);
int custom_atoi(char *);
int _strcspn(char *, char *);
void handle_ctrlc(int);
void exec_parsed_cmd(char **, int);
void handle_ctrld(int);
void ignore_comment_str(char *);
int parse_processed_cmds(char *);
char *check_for_valid_path(char *);
void (*ptr_func(char *))(char **);
char *sys_getenv(char *);
extern void basic_mode(void);
extern void shell_init_func(char **active_simple_cmd,
int type_simple_cmd);
void *custom_realloc(void *pointer, unsigned int current_size,
unsigned int realloc_size);
/**structs and others*/
#define min(a, b) (((a) < (b)) ? (a) : (b))
/**
 * struct obj - a struct that maps cmd name to corresponding func 
 * @_cmd_: command name of the command
 * @function: the function pointer to the cmd
*/
typedef struct obj
{
	char *_cmd_;
	void (*function)(char **cmd);
} obj_mapper;

#endif