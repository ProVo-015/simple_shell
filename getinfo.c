#include "shell.h"

/**
 * clear_info - resets info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
	info->argv = NULL;
	info->arg = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - resets info_t struct
 * @av: argument vector
 * @info: struct address
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;
		replace_vars(info);
		replace_alias(info);
	}
}

/**
 * free_info - free info_t struct fields
 * @all: true if free all fields
 * @info: struct address
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}

