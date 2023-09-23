#include "shell.h"
/**
 * _strcat - this function concatenates two strings
 * @_src:  target string to be concatenate
 * @_dest: target destination of concatenated string
 * Return: Returns memory location of new string
*/
char *_strcat(char *_dest, char *_src)
{
int dest_len_of_str = _strlen(_dest);
char *concatinated =  NULL;
int src_len_of_str = _strlen(_src);

concatinated = malloc(sizeof(*concatinated) * (dest_len_of_str +
src_len_of_str + 1));
_strcpy(_dest, concatinated);
_strcpy(_src, concatinated + dest_len_of_str);
concatinated[dest_len_of_str + src_len_of_str] = '\0';
return (concatinated);
}
/**
 * _strcmp - this func compares length of two strings
 * @argument_one: first target string
 * @argument_two: second target string
 * Return: diff strlen
*/
int _strcmp(char *argument_one, char *argument_two)
{
int index = 0;

while (argument_one[index] != '\0')
{
if (argument_one[index] != argument_two[index])
{
break;
}
index++;
}
return (argument_one[index] - argument_two[index]);
}
/**
 * _strcspn - this calculates segment of first_str that has
 * chars not in second_str
 * @first_str: target lookup string
 * @second_str: target dependency string
 * Return: Returns char from first_str in second_str
*/
int _strcspn(char *first_str, char *second_str)
{
int index, str_len = 0;

for (index = 0; first_str[index] != '\0'; index++)
{
if (_strchr(second_str, first_str[index]) != NULL)
{
break;
}
str_len++;
}
return (str_len);
}
/**
 * _strspn - this function calculates the length of a string
 * @first_string: target string to be looked up
 * @second_string: target string to be looked up against
 * Return: Retuns number of bytes
*/
int _strspn(char *first_string, char *second_string)
{
int match_found = 0, index = 0;

while (first_string[index] != '\0')
{
if (_strchr(second_string, first_string[index]) == NULL)
{
break;
}
match_found++;
index++;
}
return (match_found);
}
/**
 * _strchr - this function locates a chararacter
 * in a certain string
 * @_string: target string to be looked up
 * @_character: target character to be looked up againts
 * Return: Returns a ptr to the first occurence of a _character in _string
*/
char *_strchr(char *_string, char _character)
{
int index = 0;

for (; _string[index] != _character && _string[index] != '\0'; index++)
	;
if (_string[index] == _character)
{
return (_string + index);
}
else
return (NULL);
}
