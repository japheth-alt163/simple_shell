#include "shell.h"
#define MAX_INPUT_SIZE 1024
/**
 * display_prompt - displays the command-line prompt
 */
void display_prompt(void)
{
printf("#cisfun$ ");
fflush(stdout);
}
/**
 * execute_command - tries to execute external programs with
 * arguments
 * @command_line: the command line with arguments
 */
void execute_command(const char *command_line)
{
pid_t child_pid = fork();
int status;

if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
char *args[MAX_INPUT_SIZE];
char *token = strtok((char *)command_line, " ");
int i = 0;

while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

if (execve(args[0], args, NULL) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
{
if (wait(&status) == -1)
{
perror("wait");
}
}
}
/**
 * main - Entry point of the shell program
 * Return: command_line (True)
*/
int shell_main(void)
{
char input[MAX_INPUT_SIZE];
while (1)
{
display_prompt();
if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}
input[strcspn(input, "\n")] = '\0';
if (strcmp(input, "exit") == 0)
{
break;
}
execute_command(input);
}
return (EXIT_SUCCESS);
}
