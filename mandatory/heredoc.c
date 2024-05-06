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

char	*extract_env_value(char *args, int *index)
{
	char	*value;
	int		last;
	char	*var_name;

	value = NULL;
	last = *index;
	if (args[*index + 1] == '?')
	{
		value = ft_itoa(mini_shell()->exit_status);
		*index += 2; // Skip $? sequence
	}
	else
	{
		while (args[++(*index)] && ft_isalpha(args[*index]))
			continue ;  // Move index to end of variable name
		var_name = ft_substr(args, last + 1, *index - (last + 1)); // +1 skips the '$'
		value = ft_get_env(var_name);
		free(var_name);
	}
	return (value);
}

char	*dollar_finder(char *args)
{
	int i = 0;
	int size = ft_strlen(args);
	char *result = NULL;
	char *temp = NULL;

	while (i < size) {
		if (args[i] == '$')
		{
			char *env_value = extract_env_value(args, &i);  // i will be updated inside
			temp = result;
			result = ft_strjoin(result, env_value);
			free(temp);
			free(env_value);
		}
		else
		{
			char next_part[2] = {args[i], '\0'};
			temp = result;
			result = ft_strjoin(result, next_part);
			free(temp);
		}
		i++;
	}
	return result;
}

char	*hexpand(char *args)
{
	char	*str;

	str = dollar_finder(args);
	free(args);
	return (str);
}

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

int	heredoc(char *args)
{
	heredoc_signals();
	if (mini_shell()->fd_in > STDIN_FILENO)
		close(mini_shell()->fd_in);
	if (!fork())
		hreader(args);
	ignore_signals();
	waitpid(0, NULL, 0);
	signals();
	return (open("heredoc", O_RDONLY));
}
