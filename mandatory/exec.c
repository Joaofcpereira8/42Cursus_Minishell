/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:49 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/29 11:27:10 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*path_join(char *path, char *cm)
{
	char	*slashed;

	slashed = ft_strjoin(path, "/");
	slashed = ft_strjoin(slashed, cm);
	//free(slashed);
	return(slashed);
}

void	get_paths(t_data *data)
{
	data->paths = ft_split(ft_get_env("PATH"), ':');
}

void	exec_command(t_data *data, char **args, t_mini_env *envp)
{
	char	    *path;
	pid_t	    pid;
	int		    i;

	i = 0;
		get_paths(data);
		while (data->paths[i])
		{
			path = path_join(data->paths[i], args[0]);
			if (access(path, X_OK) == 0)
			{
				pid = fork();
				if (pid == 0)
					execve(path, args, envp->env);
				wait(NULL);
				break ;
			}
			else if (!data->paths[i + 1])
				perror("execve");
			i++;
		}
}
