#include "shell.h"

/**
 * custom_printf - prints a string to stdout
 * @str: target string to be printed
 * @strm: streams input to printf to print out
 * Return: Returns void/nothing
*/

void custom_printf(char *str, int strm)
{
int index = 0;

for (; str[index] != '\0'; index++)
{
write(strm, &str[index], 1);
}
}

/**
 * remove_newline_character - removes new line character
 * from a string
 * @str: string parameter to be used
 *Return: Returns nothing
*/

void remove_newline_character(char *str)
{
int count = 0;

while (str[count] != '\0')
{
if (str[count] == '\n')
{
break;
}
count++;
}
str[count] = '\0';
}

/**
 * token_processor - this is the tokenizer function that processes
 * input and stores it into an array
 *@delimiter: delimiter to be used, needs to be one character string
 *@usr_input_string: the user input to be parsed
 *Return: Returns an array of processed words (tokens)
*/

char **token_processor(char *usr_input_string, char *delimiter)
{
int count_delimiter = 0;
char *pointer_ref = NULL;
char *processed_token = NULL;
char **_argv = NULL;

processed_token = cutomized_strtok_for_shell(usr_input_string, delimiter,
&pointer_ref);

while (processed_token != NULL)
{
_argv = custom_realloc(_argv, sizeof(*_argv) * count_delimiter,
sizeof(*_argv) * (count_delimiter + 1));
_argv[count_delimiter] = processed_token;
processed_token = cutomized_strtok_for_shell(NULL, delimiter, &pointer_ref);
count_delimiter++;
}
_argv = custom_realloc(_argv, sizeof(*_argv) * count_delimiter,
sizeof(*_argv) * (count_delimiter + 1));
_argv[count_delimiter] = NULL;
return (_argv);
}

/**
 * _strcpy - this function copies a string to another buffer
 * @_src: the source to copy from
 * @_dest: the destination to copy to
 * Return: Returns nothing
*/

void _strcpy(char *_src, char *_dest)
{
int index = 0;

for (; _src[index] != '\0'; index++)
{
_dest[index] = _src[index];
}
_dest[index] = '\0';
}

/**
 * _strlen - counts string length
 * @str: string to be counted
 * Return: length of the string
 */
int _strlen(char *str)
{
int len = 0;

if (str == NULL)
{
return (len);
}
for (; str[len] != '\0'; len++)
{
	;
}
return (len);
}
