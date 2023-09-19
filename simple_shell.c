<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
=======
#include "shell.h"
/**
 * display_prompt - to desplay the prompt entered
 */
void display_prompt(void)
{
printf("#cisfun$ ");
fflush(stdout);
}
/**
 * execute_command - Execute the given command in a child process.
 * Tis function takes a command as input and executes it in a child process.
 * The 'command' parameter should be a null-terminated string containing the
 * command to be executed.
 *
 * @command: The command to execute.
 */
void execute_command(const char *command)
{
pid_t child_pid = fork();
>>>>>>> e5e44f5f3742ef43ecb119a675f9d7800969ff94

#define MAX_INPUT_LENGTH 1024

<<<<<<< HEAD
int main(void) {
	 pid_t pid = fork();
    char input[MAX_INPUT_LENGTH];

    while (1) {
        /* Display the prompt */
        printf("#cisfun$ ");
        fflush(stdout);
=======
if (wait(&status) == -1)
{
perror("wait");
}
}
}
/**
 * main - Entry point of the simple shell program.
 *
 * This function reads user commands, displays a prompt,
 * and executes the provided commands in child processes.
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int main(void)
{
char input[MAX_INPUT_SIZE];
>>>>>>> e5e44f5f3742ef43ecb119a675f9d7800969ff94

        /* Read a line of input */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            /* Handle Ctrl+D (end of file) */
            printf("\n");
            break;
        }

        /* Remove the newline character at the end */
        input[strcspn(input, "\n")] = '\0';

        /* Fork a new process */
        
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */

            /* Execute the command */
            if (execlp(input, input, (char *)NULL) == -1) {
                /* Handle the error if the command couldn't be executed */
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */

            /* Wait for the child to finish */
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}
