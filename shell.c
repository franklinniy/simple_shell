#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - shell loop
 *
 * Description: reads input from the uset
 *
 * Return: the result is always 0 to show success
*/

#define MAX_INPUT_SIZE 1024

int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)

	{
		printf("mysh>");
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		printf("You entered: %s\n", input);
	}
	return (0);
}
