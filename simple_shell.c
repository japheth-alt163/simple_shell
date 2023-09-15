#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - to desplay the prompt entered
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * execute_command - Execute the given command in a child process
 *
 * This function takes a command as input and executes it in a child process.
 * The 'command' parameter should be a null-terminated string containing the
 * command to be executed.
 *
 * @parameter  command The command to execute.
 */
void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		/* This code is executed by the child process */
		if (execlp(command, command, NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* This code is executed by the parent process */
		int status;

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

	while (1)
	{
		display_prompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D) */
			printf("\n");
			break;
		}

		/* Remove the trailing newline character */
		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) == 0)
		{
			continue; /* Empty input, prompt again */
		}

		execute_command(input);
	}

	return (EXIT_SUCCESS);
}
