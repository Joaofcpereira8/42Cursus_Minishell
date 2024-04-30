/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:25 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/30 15:18:07 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*dollar_finder(char *args)
{
	int		i;
	int		size;
	int		last;
	char	*str;
	char	*tmp1;
	char	*tmp2;

	tmp2 = NULL;
	size = (int)ft_strlen(args);
	i = 0;
	last = 0;
	while (i < size)
	{
		tmp2 = ft_strdup(ft_substr(args, last, i - 1));
		if (args[i] == '$')
		{
			if (args[i + 1] == '?')
				tmp1 = ft_strdup(ft_itoa(mini_shell()->exit_status));
			else
			{
				last = i;
				while (args[i] && ft_isalpha((int)args[i]))
					i++;
				tmp1 = ft_get_env(ft_substr(args, last, i));
			}
			str = ft_strjoin(tmp2, tmp1);
			free(tmp1);
			last = i;
		}
		else
			str = ft_strjoin(str, tmp2);
		free(tmp2);
		i++;
	}
	return (str);
}

char	*hexpand(char *args)
{
	char	*str;

	str = ft_strdup(dollar_finder(args));
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
		else if (ft_strcmp(input, args) == 0)
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
}
