/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:55:05 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/25 12:40:37 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

pid_t   exec_is_fork(t_a_s_tree *command)
{
    pid_t   pid;

    child_signals();
    pid = fork();
    if (pid == 0)
    {
        if (mini_shell()->fd_in == -1 || mini_shell()->fd_out == 1)
        {
            //dar free
        }
        atribute_fd_pipes(command->index);
        fd_duplicate();
        built_type(NULL);
    }
    return (pid);
}

void	execute(t_a_s_tree *ast)
{
	int		status;
	pid_t	last;

	status = 0x7F; //exit status 127
	pipes_generate();
	last = execute_pipes(ast);
	last = waitpid(last, &status, 0);
	while (waitpid(last, NULL, 0) > 0)
        continue ;
    if (WIFEXITED(status))
        mini_shell()->exit_status = WEXITSTATUS(status);
    signals();
}

/*
 * 127 error code indicates “command not found”. This occurs when any
 * given command within your Bash script or on Bash command line is not
 * found in any of the paths defined by PATH system environment variable.
 */