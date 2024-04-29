/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:25 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/29 18:45:07 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*int *where_dollar(char *args)
{
	int i;
	int n;
	int	*pos;

	i = -1;
	while (args[++i])
		if(args[i] == '$')
			n++;
	pos = malloc(sizeof(int) * n);
	i = -1;
	n = -1;
	while (args[++i])
	{
		if (args[i] == '$')
		{
			pos[++n] = i;
			while (args[i] && ft_isalnum((int)args[i]))
				i++;
			pos[++n] = i;
		}
	}
	return (pos);
}


char	*dollar_finder(char *args)
{
	int 	i;
	int 	last;
	int		size;
	int		*pos;
	char 	*str;
	char	*tmp;
	char	*value;

	size = (int)ft_strlen(args);
	pos = where_dollar(args);
	last = 0;
	while (pos[i])
	{
		tmp = (ft_substr(args, last, pos[i]), );
		tmp = ft_get_env();
		str = ft_strjoin(str, tmp);
		free(tmp);
		last = pos[i + 1];
		i += 2;
	}
	free(pos);
}*/

char	*dollar_finder(char *args)
{
	int		i;
	int		size;
	int		last;
	char	*str;
	char	*tmp1;
	char	*tmp2;

	size = (int)ft_strlen(args);
	i = 0;
	last = 0;
	while (i < size)
	{
		if (args[i] == '$')
		{
			// tmp2 = ft_strdup(ft_substr(args, last, i - 1));
			if (args[i + 1] == '?')
				tmp1 = ft_strdup(ft_itoa(mini_shell()->exit_status));
			else
			{
				last = i;
				while (args[i] && ft_isalnum((int)args[i]))
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
	// return (err_handler('h', "", 0));
}
