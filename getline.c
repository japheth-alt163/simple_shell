#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024

/* Function to read a line of input into a buffer */
char *custom_getline(void) {
	char buffer[MAX_INPUT_SIZE];
	int position = 0;
	int bytesRead = 0;
	char c;

	while (1) {
		/* Check if we need to read more data into the buffer */
		if (position >= bytesRead) {
			position = 0;
			bytesRead = read(STDIN_FILENO, buffer, MAX_INPUT_SIZE);
			if (bytesRead <= 0) {
				/* No more data to read */
				return NULL;
			}
		}

		c = buffer[position++];
		if (c == '\n' || c == '\0') {
			buffer[position - 1] = '\0'; /* Null-terminate the string */
			return buffer;
		}
	}
}

int getline_main(void) {
	char *input;

	while (1) {
		/* Print a prompt */
		printf("Shell > ");

		/* Read input using custom_getline */
		input = custom_getline();

		if (input == NULL) {
			/* No more input, exit the shell */
			break;
		}

		/* Process the input (you can implement your shell logic here) */
		/* For simplicity, we'll just print the input for now */
		printf("You entered: %s\n", input);

		/* Free the input buffer */
		/* Note: In a real shell, you would parse and execute commands here */
		/* and handle memory management accordingly. */
	}

	return 0;
}
