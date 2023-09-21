#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024

/* Function to read a line of input into a dynamically allocated buffer */
char *custom_getline(void) {
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t bytesRead;

    /* Use getline to dynamically allocate memory for the input */
    bytesRead = getline(&buffer, &bufsize, stdin);

    if (bytesRead == -1) {
        /* Error or end of input */
        free(buffer);
        return NULL;
    }

    if (bytesRead > 0 && buffer[bytesRead - 1] == '\n') {
        /* Remove newline character if present */
        buffer[bytesRead - 1] = '\0';
    }

    return buffer;
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
        free(input);
        /* Note: In a real shell, you would parse and execute commands here */
        /* and handle memory management accordingly. */
    }

    return 0;
}

