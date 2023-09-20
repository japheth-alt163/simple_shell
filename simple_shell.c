#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - displays the comand- line prompt
*/
void display_prompt(void)
{
printf("#cisfun$ ");
fflush(stdout);
}

/**
 * execute_command - tries to verify the command passed to it
 * and execute it
 * @command: the command param
*/
void execute_command(const char *command)
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
if (execlp(command, command, NULL) == -1)
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
int main(void)
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
