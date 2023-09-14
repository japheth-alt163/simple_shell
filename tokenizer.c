#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 32

/* Display the shell prompt. */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/* Execute the given command with arguments in a child process. */
void execute_command(char *command, char *args[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		/* This code is executed by the child process */
		if (execvp(command, args) == -1)
		{
			perror("execvp");
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
 * and executes the provided commands with arguments in child processes.
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
        char *args[MAX_ARG_COUNT];
        int arg_count = 0;
        char *token;

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

		/* Tokenize the input to separate command and arguments */
         	arg_count = 0;
		token = strtok(input, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		if (arg_count > 0)
		{
			execute_command(args[0], args);
		}
	}

	return (EXIT_SUCCESS);
}
