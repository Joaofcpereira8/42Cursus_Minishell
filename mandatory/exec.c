/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:49 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/19 23:16:58 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*path_join(char *path, char *cm)
{
	char	*slashed;

    //free(slashed);
	slashed = ft_strjoin(path, "/");
	slashed = ft_strjoin(slashed, cm);
	return (slashed);
}

void	get_paths(char **path)
{
    path = ft_split(ft_get_env("PATH"), ':');
}

void exec_command(char **args)
{
	char	*path;
	pid_t	pid;
	int		i;

	i = 0;
	get_paths(mini_shell()->path);
	while (mini_shell()->path[i])
	{
		path = path_join(mini_shell()->path[i], args[0]);
		if (access(path, X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(path, args, mini_shell()->env);
			wait(NULL);
			break ;
		}
		else if (!mini_shell()->path[i + 1])
			perror("execve");
		i++;
	}
}
