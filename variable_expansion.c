#include "shell.h"

/**
 * expand_variables - expands variables in a string
 * @line: the line containing variables
 *
 * Return: new string with variables expanded
 */
char *expand_variables(char *line)
{
	char *expanded, *var_value, *temp;
	char var_name[256];
	int i = 0, j = 0, k;

	expanded = malloc(4096);
	if (!expanded)
		return (NULL);

	while (line[i])
	{
		if (line[i] == '$')
		{
			i++;
			if (line[i] == '?')
			{
				sprintf(var_name, "%d", last_exit_status);
				strcpy(&expanded[j], var_name);
				j += strlen(var_name);
				i++;
			}
			else if (line[i] == '$')
			{
				sprintf(var_name, "%d", getpid());
				strcpy(&expanded[j], var_name);
				j += strlen(var_name);
				i++;
			}
			else if (line[i] == ' ' || line[i] == '\0')
			{
				expanded[j++] = '$';
			}
			else
			{
				k = 0;
				while (line[i] && (line[i] == '_' ||
					(line[i] >= 'A' && line[i] <= 'Z') ||
					(line[i] >= 'a' && line[i] <= 'z') ||
					(line[i] >= '0' && line[i] <= '9')))
				{
					var_name[k++] = line[i++];
				}
				var_name[k] = '\0';
				var_value = _getenv(var_name);
				if (var_value)
				{
					strcpy(&expanded[j], var_value);
					j += strlen(var_value);
				}
			}
		}
		else
		{
			expanded[j++] = line[i++];
		}
	}
	expanded[j] = '\0';

	temp = strdup(expanded);
	free(expanded);
	return (temp);
}

/**
 * process_line_variables - processes a line for variable expansion
 * @line: the line to process
 *
 * Return: expanded line
 */
char *process_line_variables(char *line)
{
	char *expanded;

	if (strchr(line, '$') == NULL)
		return (line);

	expanded = expand_variables(line);
	if (expanded)
	{
		free(line);
		return (expanded);
	}
	return (line);
}
