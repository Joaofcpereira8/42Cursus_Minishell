/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:49 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/03 11:36:28 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*path_join(char *path, char *cmd)
{
	char	*temp;
	char	*slashed;

	temp = ft_strjoin(path, "/");
	slashed = ft_strjoin(temp, cmd);
	free(temp);
	return (slashed);
}

char	**get_paths(void)
{
	char	*split_path;

	list_delete(mini_shell()->path);
	split_path = ft_get_env("PATH");
	mini_shell()->path = ft_split(split_path, ':');
	if (split_path)
		free (split_path);
	if (!mini_shell()->path)
		return (NULL);
	return (mini_shell()->path);
}

void	absolute_input(char **args)
{
	if (access(args[0], X_OK) == 0)
		execve(args[0], args, mini_shell()->env);
	else
		perror("execve path directly");
}

void	exec_command(char **args)
{
	char	*joined_path;
	int		i;

	if (ft_strchr(args[0], '/'))
		return (absolute_input(args));
	i = 0;
	mini_shell()->path = get_paths();
	while (mini_shell()->path[i])
	{
		joined_path = path_join(mini_shell()->path[i], args[0]);
		if (joined_path)
		{
			if (access(joined_path, X_OK) == 0)
			{
				execve(joined_path, args, mini_shell()->env);
			}
			free(joined_path);
		}
		else if (!mini_shell()->path[i + 1])
			perror("execve");
		i++;
	}
	printf("%s: command not found\n", *args);
	mini_shell()->exit_status = 127;
}
