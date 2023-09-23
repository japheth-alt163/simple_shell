#include "shell.h"
/**
* handle_ctrld - this functions handles signal interupt => CTRL-D
* @sig: signal value (number)
* Return: returns nothing
*/
void handle_ctrld(int sig)
{
if (sig == SIGQUIT)
{
printf("\n");
exit(0);
}
}
int status = 0; /*status*/
char **parsed_cmds; /*commands*/
char *cmd_line; /*line*/
char *prompt; /*shell_name*/
/**
* main - the entry point of the shell program
* @argc_arr: the number of arguments passed to main function
* @argv_arr: the program arguments to be parsed to main function
* Return: 0 on success, 1 otherwise
*/
int main(int argc_arr __attribute__((unused)), char **argv_arr)
{

int indexer, type_simple_cmd = 0;
char **active_simple_cmd = NULL;
size_t counter_var = 0;

signal(SIGINT, handle_ctrlc);
signal(SIGQUIT, handle_ctrld);
prompt = argv_arr[0];
while (1)
{
basic_mode();
custom_printf("$ ", STDOUT_FILENO);
if (getline(&cmd_line, &counter_var, stdin) == -1)
{
free(cmd_line);
exit(status);
}
remove_newline_character(cmd_line);
ignore_comment_str(cmd_line);
parsed_cmds = token_processor(cmd_line, ";");

for (indexer = 0; parsed_cmds[indexer] != NULL; indexer++)
{
active_simple_cmd = token_processor(parsed_cmds[indexer], " ");
if (active_simple_cmd[0] == NULL)
{
free(active_simple_cmd);
break;
}
type_simple_cmd = parse_processed_cmds(active_simple_cmd[0]);
shell_init_func(active_simple_cmd, type_simple_cmd);
free(active_simple_cmd);
}
free(parsed_cmds);
}
free(cmd_line);
return (status);
}
