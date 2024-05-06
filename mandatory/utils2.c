/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:06 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/06 12:15:13 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

bool	is_built_in(char *command, char *arg)
{
	return ((!ft_strcmp(command, "cd"))
		|| (!ft_strcmp(command, "export") && arg)
		|| (!ft_strcmp(command, "unset")) || (!ft_strcmp(command, "exit")));
}

bool	is_last_command(int command_numbers)
{
	return (command_numbers == mini_shell()->cmd_num - 1);
}

void	fd_duplicate(void)
{
	if (mini_shell()->fd_in >= STDIN_FILENO)
		dup2(mini_shell()->fd_in, STDIN_FILENO);
	if (mini_shell()->fd_out >= STDOUT_FILENO)
		dup2(mini_shell()->fd_out, STDOUT_FILENO);
}

void	fd_close(int command_index)
{
	if (mini_shell()->fd_in != STDIN_FILENO)
		close(mini_shell()->fd_in);
	if (mini_shell()->fd_out != STDOUT_FILENO)
		close(mini_shell()->fd_out);
	if (command_index > 0)
		close(mini_shell()->pipes[command_index - 1][RE_PI]);
	if (!is_last_command(command_index))
		close(mini_shell()->pipes[command_index][WR_PI]);
	mini_shell()->fd_in = STDIN_FILENO;
	mini_shell()->fd_out = STDOUT_FILENO;
}
