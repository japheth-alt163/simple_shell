#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 32

/* Rename display_prompt to tokenizer_display_prompt */
void tokenizer_display_prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout);
}

/* Rename execute_command to tokenizer_execute_command */
void tokenizer_execute_command(char *command, char *args[])
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

int tokenizer_main(void)
{
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_COUNT];
    int arg_count = 0;
    char *token;

    while (1)
    {
        tokenizer_display_prompt();

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

        while (token != NULL && arg_count < MAX_ARG_COUNT - 1)
        {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if (arg_count > 0)
        {
            tokenizer_execute_command(args[0], args);
        }
    }

    return (EXIT_SUCCESS);
}
