#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int _extit_main(void)
{
    char *line = NULL;  /* Pointer to store user input */
    size_t len = 0;     /* Length of the input buffer */
    ssize_t read;       /* Number of characters read */
    pid_t pid;
    int status;

    while (1) {
        printf("($) ");  /* Display shell prompt */

        /* Read user input into 'line' and handle errors */
        if ((read = getline(&line, &len, stdin)) == -1) {
            if (feof(stdin)) {
                printf("\n");  /* Handle EOF (Ctrl+D) */
                break;
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        /* Check if the input is "exit" to exit the shell */
        if (strcmp(line, "exit\n") == 0) {
            free(line);      /* Free memory allocated for 'line' */
            exit(EXIT_SUCCESS);
        }

        /* Remove newline character at the end of the input */
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }

        /* Create a child process to execute the entered command */
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {  /* Child process */
            char *args[2];
            args[0] = line;
            args[1] = NULL;

            /* Execute the command and handle errors */
            if (execve(line, args, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {  /* Parent process */
            /* Wait for the child process to complete and handle errors */
            if (wait(&status) == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    free(line);  /* Free memory allocated for 'line' */
    exit(EXIT_SUCCESS);
}
