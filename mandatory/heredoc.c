/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:25 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:13:59 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*dollar_finder(char *args)
{
	int		i;
	int		start;
	char	*var;

	i = 0;
	while (args[i])
	{
		if (args[i] == '$')
		{
			start = i;
			if (args[i + 1] == '?')
				var = ft_strdup(ft_itoa(mini_shell()->exit_status));
			while (args[i] && ft_isalnum((int)args[i]))
				i++;
			var = ft_substr(args, start, i);
			free(var);
		}
		i++;
	}
	return (args);
}

char	*hexpand(char *args)
{
	char	*str;
	char	*value;
	char	*key;

	str = ft_strdup(args);
	while (ft_strnstr(str, "$", ft_strlen(str)))
	{
/*		key = _find_key(str);
		str = ft_strreplace(str, key, value);*/
		str = dollar_finder(args);
		free(key);
		free(value);
	}
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
			break ;
		}
		else if (input && !ft_strcmp(input, args))
		{
			free(input);
			break ;
		}
		input = hexpand(input);
		ft_putendl_fd(input, fd);
		free(input);
	}
	close(fd);
	ft_free();
	ft_free_all();
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
	// return (err_handler('h', "", 0));
}
