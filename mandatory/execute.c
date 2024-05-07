/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:55:05 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/07 17:48:57 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

pid_t	exec_is_fork(t_a_s_tree *command)
{
	pid_t	pid;

	child_signals();
	pid = fork();
	if (pid == 0)
	{
		if (mini_shell()->fd_in == -1 || mini_shell()->fd_out == -1)
		{
			ft_free();
			ft_free_all();
		}
		atribute_pipes_fd(command->index);
		fd_duplicate();
		if (mini_shell()->close_p == 0)
			close_all_pipes();
		built_type(command->args);
		ft_free();
		ft_free_all();
	}
	fd_close(command->index);
	return (pid);
}

void	execute(t_a_s_tree *ast)
{
	int		status;
	pid_t	last;

	status = 0x7F;
	pipes_generate();
	last = execute_pipes(ast);
	last = waitpid(last, &status, 0);
	while (waitpid(0, NULL, 0) > 0)
		continue ;
	if (WIFEXITED(status))
		mini_shell()->exit_status = WEXITSTATUS(status);
	signals();
}
