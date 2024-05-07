/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:25 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/06 12:26:56 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"


void	hreader(char *args)
{
	int		fd;
	char	*input;

	fd = open("heredoc", O_WRONLY | O_CREAT | O_APPEND, 0666);
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			printf("\n");
			ft_free();
			ft_free_all();
		}
		else if (ft_strcmp(input, args) == 0)
		{
			free(input);
			ft_free();
			ft_free_all();
		}
		input = hexpand(input);
		ft_putendl_fd(input, fd);
		free(input);
	}
	close(fd);
}

char	*extract_env_value(char *args, int *index)
{
	char	*value;
	char	*var_name;
	int		last;

	value = NULL;
	var_name = NULL;
	last = *index;
	if (args[*index + 1] == '?')
	{
		*index += 2; // Skip $? sequence
		return (ft_itoa(mini_shell()->exit_status));
	}
	*index += 1;
	while (args[*index] && ft_isalpha(args[*index]))
		*index += 1;
	var_name = ft_substr(args, last + 1, *index - (last + 1)); // +1 skips the '$'
	value = ft_get_env(var_name);
	free(var_name);
	return (value);
}

// Function to handle appending characters and expanding environment variables.
char	*process_char(char *args, int *i, char *result)
{
	char	next_part[2];
	char	*temp;
	char	*env_value;

	if (args[*i] == '$')
	{
		env_value = extract_env_value(args, i);
		temp = result;
		result = ft_strjoin(result, env_value);
		free(temp);
		free(env_value);
	}
	else
	{
		next_part[0] = args[*i];
		next_part[1] = '\0';
		temp = result;
		result = ft_strjoin(result, next_part);
		free(temp);
	}
	return (result);
}

// Main function to find and replace all "$" occurrences with their corresponding env values.
char	*dollar_finder(char *args)
{
	int		i;
	int		size;
	char	*result;

	i = 0;
	result = NULL;
	size = ft_strlen(args);
	while (i < size)
	{
		result = process_char(args, &i, result);
		i++;
	}
	return (result);
}

char	*hexpand(char *args)
{
	char	*str;

	str = dollar_finder(args);
	free(args);
	return (str);
}
