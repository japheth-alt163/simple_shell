#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Description: This program calculates the sum of two integers and
 *              prints a message based on the value of the sum.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a, b, c;

	printf("Enter the values of a and b:\n");
	scanf("%d %d", &a, &b);
	c = a + b;
	printf("Sum is %d", c);
	if (c > 20)
	{
		printf("\nSum is greater than 20");
	}
	else if (c > 15)
	{
		printf("\nSum is greater than 15");
	}
	else if (c > 10)
	{
		printf("\nSum is less than 10");
	}

	return (0);
}

