#define MAX_INPUT_LENGTH 1024

int main(void) {
	pid_t pid = fork();
    char input[MAX_INPUT_LENGTH];

    while (1) {
        /* Display the prompt */
        printf("#cisfun$ ");
        fflush(stdout);

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
