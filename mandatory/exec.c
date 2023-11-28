/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:49 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/28 17:06:07 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	data->paths = ft_split(getenv("PATH"), ':');
}

void	exec_command(t_data *data, char **args, char **env)
{
	char	*path;
	pid_t	pid;
	int		i;

	pid = fork();
	i = 0;
	if (pid < 0)
		perror("fork");
	else if (pid == 0)
	{
		get_paths(data);
		path = path_join(data->paths[i], args[0]);
		while (data->paths[i])
		{
			if (access(path, X_OK) == 0)
				execve(path, args, env);
			else if (!data->paths[i + 1])
				perror("execve");
			i++;
		}
		return ;
	}
}
