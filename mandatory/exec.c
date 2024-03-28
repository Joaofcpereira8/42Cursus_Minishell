/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:49 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/28 18:26:10 by jofilipe         ###   ########.fr       */
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

char	**get_paths(void)
{
	char	*split_path;
	char	**paths;

	if (!split_path)
		return (NULL);//Handle case where PATH environment variable doesn't exist
	// Split the PATH using ft_split (assuming it returns an array of char*)
	split_path = ft_get_env("PATH");
	paths = ft_split(split_path, ':');
	// Handle potential allocation failure from ft_split
	if (!paths)
		return (NULL);
	return paths;
}

void	exec_command(char **args)
{
	char	**path;
	char	*joined_path;
	pid_t	pid;
	int		i;

	i = 0;
	path = get_paths();
	while (path[i])
	{
		joined_path = path_join(path[i], args[0]);
		if (joined_path)
		{
			if (access(joined_path, X_OK) == 0)
			{
				pid = fork();
				if (pid == 0)
					execve(joined_path, args, mini_shell()->env);
				wait(NULL);
				break ;
			}
			free(joined_path);
		}
		else if (!mini_shell()->path[i + 1])
			perror("execve");
		i++;
	}
}
