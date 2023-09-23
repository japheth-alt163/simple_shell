#include "shell.h"
/**
 * quit - exits the shell
 * @simple_cmd: command entered
 * @simple_cmd: a simple command parameter
 * Return: nothing to return here
 */
void quit(char **simple_cmd)
{
int args, tokenCounter = 0;

for (; simple_cmd[tokenCounter] != NULL; tokenCounter++)
	;
if (tokenCounter == 1)
{
free(simple_cmd);
free(cmd_line);
free(parsed_cmds);
exit(status);
}
else if (tokenCounter == 2)
{
args = custom_atoi(simple_cmd[1]);
if (args == -1)
{
custom_printf(prompt, STDERR_FILENO);
custom_printf(": 1: exit: Illegal number: ", STDERR_FILENO);
custom_printf(simple_cmd[1], STDERR_FILENO);
custom_printf("\n", STDERR_FILENO);
status = 2;
}
else
{
free(cmd_line);
free(simple_cmd);
free(parsed_cmds);
exit(args);
}
}
else
custom_printf("$: too many arguments\n", STDERR_FILENO);
}

/**
 * _env - prints the the environment of the
 * current user in session
 * @simple_cmd: a simple command parameter
 * Return: nothing to return here
 */
void env(char **simple_cmd __attribute__((unused)))
{
int count;

for (count = 0; environ[count] != NULL; count++)
{
custom_printf(environ[count], STDOUT_FILENO);
custom_printf("\n", STDOUT_FILENO);
}
}
