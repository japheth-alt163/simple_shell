#include "shell.h"
/**
 * shell_init_func - this function initializes and executes everything
 * @type_simple_cmd: target token to parse
 * @active_simple_cmd: attempts to get and process current token
 * Return: Returns nothing
*/
void shell_init_func(char **active_simple_cmd, int type_simple_cmd)
{
pid_t activePid;

if (type_simple_cmd == HANDLE_EXT_CMD || type_simple_cmd == HANDLE_PATH)
{
activePid = fork();
if (activePid == 0)
{
exec_parsed_cmd(active_simple_cmd, type_simple_cmd);
}
else
{
waitpid(activePid, &status, 0);
status >>= 8;
}
}
else
{
exec_parsed_cmd(active_simple_cmd, type_simple_cmd);
}
}
