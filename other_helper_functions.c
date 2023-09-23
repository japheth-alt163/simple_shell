#include "shell.h"
/**
* exec_parsed_cmd - this function executes the parsed cmd
* @parsed_command: tokenized/parsed form of the input command
* @type_of_cmd: the type of the command
* Return: Returns nothing
*/
void exec_parsed_cmd(char **parsed_command, int type_of_cmd)
{
void (*function)(char **cmd);

if (type_of_cmd == HANDLE_EXT_CMD)
{
if (execve(parsed_command[0], parsed_command, NULL) == -1)
{
perror(sys_getenv("PWD"));
exit(2);
}
}
if (type_of_cmd == HANDLE_PATH)
{
if (execve(check_for_valid_path(parsed_command[0]),
parsed_command, NULL) == -1)
{
perror(sys_getenv("PWD"));
exit(2);
}
}
if (type_of_cmd == HANDLE_INT_CMD)
{
function = ptr_func(parsed_command[0]);
function(parsed_command);
}
if (type_of_cmd == HANDLE_INVALID_CMD)
{
custom_printf(prompt, STDERR_FILENO);
custom_printf(": 1: ", STDERR_FILENO);
custom_printf(parsed_command[0], STDERR_FILENO);
custom_printf(": not found\n", STDERR_FILENO);
status = 127;
}
}

/**
 * parse_processed_cmds - this function identifies command
 * @cmd: target command to be parsed
 * Description - this funtion makes use of certain commands defined in shell.h
 * header file
 * Return: Returns a constant reping the type of the cmd
*/
int parse_processed_cmds(char *cmd)
{
int indexer;
char *temp_path = NULL;
char *built_in_cmd[] = {"env", "exit", NULL};

for (indexer = 0; cmd[indexer] != '\0'; indexer++)
{
if (cmd[indexer] == '/')
{
return (HANDLE_EXT_CMD);
}
}
for (indexer = 0; built_in_cmd[indexer] != NULL; indexer++)
{
if (_strcmp(cmd, built_in_cmd[indexer]) == 0)
{
return (HANDLE_INT_CMD);
}
}
temp_path = check_for_valid_path(cmd);
if (temp_path != NULL)
{
free(temp_path);
return (HANDLE_PATH);
}
return (HANDLE_INVALID_CMD);
}

/**
* check_for_valid_path - this function checks if a valid cmd is
* present in the PATH env present
* @cmd: the command to be parsed
* Return: Returns the valid path of the command, NULL if otherwise
*/
char *check_for_valid_path(char *cmd)
{
char *secondary, *temp_copy, *primary;
char *the_actual_path = sys_getenv("PATH");
char **path_tray = NULL;
int indexer;

if (the_actual_path == NULL || _strlen(the_actual_path) == 0)
{
return (NULL);
}
temp_copy = malloc(sizeof(*temp_copy) * (_strlen(the_actual_path) + 1));
_strcpy(the_actual_path, temp_copy);
path_tray = token_processor(temp_copy, ":");
for (indexer = 0; path_tray[indexer] != NULL; indexer++)
{
secondary = _strcat(path_tray[indexer], "/");
primary = _strcat(secondary, cmd);
if (access(primary, F_OK) == 0)
{
free(secondary);
free(path_tray);
free(temp_copy);
return (primary);
}
free(primary);
free(secondary);
}
free(temp_copy);
free(path_tray);
return (NULL);
}

/**
* ptr_func - this function will retrieve a function based on the command
* @cmd: target string to look up against while mapping
* Return: Returns a pointer to the actual func, null on failure
*/
void (*ptr_func(char *cmd))(char **)
{
int indexer;
obj_mapper thisDotMapTo[] = {
{"env", env}, {"exit", quit}
};

for (indexer = 0; indexer < 2; indexer++)
{
if (_strcmp(cmd, thisDotMapTo[indexer]._cmd_) == 0)
return (thisDotMapTo[indexer].function);
}
return (NULL);
}

/**
* sys_getenv - this function retrieves the value of an env variable
* @env_name: the name of the environment variable
* Return: Returns the value of a variable
*/
char *sys_getenv(char *env_name)
{
char *env_name_c;
char *key_value_pair;
char **tmp_env;

for (tmp_env = environ; *tmp_env != NULL; tmp_env++)
{
for (key_value_pair = *tmp_env, env_name_c = env_name;
*key_value_pair == *env_name_c; key_value_pair++, env_name_c++)
{
if (*key_value_pair == '=')
{
break;
}
}
if ((*key_value_pair == '=') && (*env_name_c == '\0'))
return (key_value_pair + 1);
}
return (NULL);
}
