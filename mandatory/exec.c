/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:49 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/22 17:58:19 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(t_data *data, char **argv, char **env)
{
	pid_t	pid;
	int		i;

	pid = fork();
	i = 0;
	if (pid < 0)
		perror("fork");
	else if (pid == 0)
	{
		//Child process
		while (data->paths[i])
		{
            split_path();//separar os paths e por a / para aceder as pastas do sistema
			if (access())
				execve(argv[0], argv, env);
			perror("execve");
			i++;
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		//Parent process
		waitpid(pid, NULL, 0);
	}
}

//void get_paths(t_data *data)
//{
//	data->paths = ft_split(getenv("PATH"), ':');
//}