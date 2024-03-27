/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:06 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/26 17:09:03 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

bool	is_built_in(char *command, char *arg)
{
	return((!ft_strcmp(command, "echo")) || (!ft_strcmp(command, "cd"))
		|| (!ft_strcmp(command, "pwd")) || (!ft_strcmp(command, "export") && arg)
		|| (!ft_strcmp(command, "unset")) || (!ft_strcmp(command, "env"))
		|| (!ft_strcmp(command, "exit")));
}

bool    is_last_command(int command_numbers)
{
    return (command_numbers = mini_shell()->cmd_num - 1);
}

void    fd_duplicate(void)
{
    if (mini_shell()->fd_in == STDIN_FILENO)
        dup2(mini_shell()->fd_in, STDIN_FILENO);
    if (mini_shell()->fd_out == STDOUT_FILENO)
        dup2(mini_shell()->fd_out, STDOUT_FILENO);
}