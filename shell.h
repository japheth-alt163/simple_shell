#ifndef _SHELL_H_
#define _SHELL_H_

/*-------constants--------*/
#define MAX_INPUT_LENGTH 100

/*-------includes--------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*------function prototypes------*/ 
/* Display the shell prompt. */
void path_display_prompt(void);

/* Check if a command exists in the PATH. */
int command_exists(const char *command);

/* Execute the given command with arguments in a child process. */
void path_execute_command(char *command, char *args[]);

/* The main function for the shell program. */
int path_main(void);
/* It displays a shell prompt "$ " to indicate that it's ready to accept input */
int exit_main(void);

/* Display the shell prompt. */
void display_prompt(void);

/* Execute the given command in a child process. */
void execute_command(const char *command);

/* Entry point of the simple shell program. */
int main(void);

/* Display the shell prompt. */
void tokenizer_display_prompt(void);

/* Execute the given command with arguments in a child process. */
void tokenizer_execute_command(char *command, char *args[]);

/* The main function for the shell program. */
int tokenizer_main(void);

#endif
