/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:05:45 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/11 11:47:14 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	redirects(t_meta_tok token, char *comm)
{
	if (token == red_out)
		(mini_shell()->fd_out) = open(comm, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (token == red_apnd)
		(mini_shell()->fd_out) = open(comm, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (token == red_in)
		(mini_shell()->fd_in) = open(comm, O_RDONLY);
	else if (token == red_hdoc)
		return (handle_hdoc(&comm));
	if (mini_shell()->fd_in == -1 || mini_shell()->fd_out == -1)
		return (pars_error('z', 1));
	return (0);
}

int	handle_hdoc(char **comm)
{
	mini_shell()->fd_in = heredoc(comm[1]);
	if (mini_shell()->fd_in)
		return (0);
	return (err_handler('r', "<<", 0));
}
