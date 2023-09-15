#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 100

/**
 * exit_main - Simple shell program
 *
 * Return: Always 0
 */
int exit_main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("$ ");

		/* Read user input and check for errors */
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}

		/* Remove the newline character */
		input[strcspn(input, "\n")] = '\0';

		/* Check if the user entered "exit" to exit the shell */
		if (strcmp(input, "exit") == 0)
		{
			exit(0); /* Exit the shell */
		}

		/* Handle other commands (you can add more here) */
		/* ... */
	}
	return (0);
}
