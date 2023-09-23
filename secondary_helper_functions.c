#include "shell.h"
/**
 * ignore_comment_characters - ignores anything after '#' char
 * @usr_input: user's input
 * Return: Returns nothing
 */
void ignore_comment_characters(char *usr_input)
{
int count = 0;

if (usr_input[count] == '#')
{
usr_input[count] = '\0';
}
while (usr_input[count] != '\0')
{
if (usr_input[count] == '#' && usr_input[count - 1] == ' ')
break;
count++;
}
usr_input[count] = '\0';
}
/**
 * custom_realloc - this realloc function reallocates a memory block
 * @pointer: pointer to the memory previously allocated with a call to malloc
 * @current_size: size of ptr
 * @realloc_size: size of the new memory to be allocated
 * Return: pointer to the address of the new memory block
 */
void *custom_realloc(void *pointer, unsigned int current_size,
unsigned int realloc_size)
{
void *temporary_buffer;
unsigned int index;

if (pointer == NULL)
{
temporary_buffer = malloc(realloc_size);
return (temporary_buffer);
}
else if (realloc_size == current_size)
{
return (pointer);
}
else if (realloc_size == 0 && pointer != NULL)
{
free(pointer);
return (NULL);
}
else
{
temporary_buffer = malloc(realloc_size);
if (temporary_buffer != NULL)
{
for (index = 0; index < min(current_size, realloc_size); index++)
{
*((char *)temporary_buffer + index) = *((char *)pointer + index);
}
free(pointer);
return (temporary_buffer);
}
else
return (NULL);
}
}
/**
 * cutomized_strtok_for_shell - this function potentially
 * tokenizes an input string
 * @ref_ptr: this pointer keeps track of tokens
 * @delimiter: stores delimiter to be used while parsing
 * the string
 * @str: target string to be parsed
 * Return: Returns the next available token in line
*/
char *cutomized_strtok_for_shell(char *str, char *delimiter, char **ref_ptr)
{
char *stop_processing;

if (str == NULL)
{
str = *ref_ptr;
}
if (*str == '\0')
{
*ref_ptr = str;
return (NULL);
}
str += _strspn(str, delimiter);
if (*str == '\0')
{
*ref_ptr = str;
return (NULL);
}
stop_processing = str + _strcspn(str, delimiter);
if (*stop_processing == '\0')
{
*ref_ptr = stop_processing;
return (str);
}
*stop_processing = '\0';
*ref_ptr = stop_processing + 1;
return (str);
}
/**
 * custom_atoi - this functions casts string to integer
 * @_string: target string to be casted
 * Return: Returns the converted string
 */
int custom_atoi(char *_string)
{
unsigned int counter = 0;

do {
if (*_string == '-')
{
return (-1);
}
else if ((*_string < '0' || *_string > '9') &&
*_string != '\0')
{
return (-1);
}
else if (*_string >= '0'  && *_string <= '9')
{
counter = (counter * 10) + (*_string - '0');
}
else if (counter > 0)
{
break;
}
} while (*_string++);
return (counter);
}

/**
 * ignore_comment_str - removes/ignores after the a '#' character
 * @input: the user input to be used
 * Return: Returns nothing
 */

void ignore_comment_str(char *input)
{
int index = 0;

if (input[index] == '#')
{
input[index] = '\0';
}
while (input[index] != '\0')
{
if (input[index] == '#' && input[index - 1] == ' ')
{
break;
}
index++;
}
input[index] = '\0';
}
