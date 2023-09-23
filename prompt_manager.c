#include "shell.h"
/**
* basic_mode - this function handles the non_interactive part of the shell
* Return: This function returns nothing
*/
void basic_mode(void)
{
size_t counter = 0;
char **active_simple_cmd = NULL;
int indexer, type_simple_cmd = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&cmd_line, &counter, stdin) != -1)
{
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
exit(status);
}
}
/**
 * handle_ctrlc - this functions handles signal interupt => CTRL-C
 * @sig: signal value
 * Return: returns nothing
*/
void handle_ctrlc(int sig)
{
if (sig == SIGINT)
{
custom_printf("\n$ ", STDIN_FILENO);
}
}
