#include "shell.h"

/**
 * interactive - if the shell is in interactive mode, returns true.
 * @inform: structs the location
 *
 * Return: 1 if the interactive  mode, 0 in any case
 */
int interactive(info_t *inform)
{
	return (isatty(STDIN_FILENO) && inform->readfd <= 2);
}

/**
 * is_delim- checks in the event that character is a delimeter
 * @d: the char to check
 * @delim: a delimeter is a string
 * Return: 0 if false, 1 if true
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 *_alpha - checks for alphabetic character
 *@d: The character to input
 *Return: 1 if d is alphabetic, 0 otherwise
 */

int _alpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - creates an integer from a string
 *@x: converts the string
 *Return: 0 if no numbers in string, changed over number in any case
 */

int _atoi(char *x)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  x[i] != '\0' && flag != 2; i++)
	{
		if (x[i] == '-')
			sign *= -1;

		if (x[i] >= '0' && x[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (x[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

