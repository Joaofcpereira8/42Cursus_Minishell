/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:37:14 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/06 12:14:12 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

bool	builtin_verif(char *command)
{
	return ((!ft_strcmp(command, "echo")) || (!ft_strcmp(command, "cd"))
		|| (!ft_strcmp(command, "pwd")) || (!ft_strcmp(command, "export"))
		|| (!ft_strcmp(command, "unset")) || (!ft_strcmp(command, "env"))
		|| (!ft_strcmp(command, "exit")));
}

bool	pipe_or_redir(t_token *token)
{
	return (token->type >= red_in && token->type <= piped);
}

bool	pipe_or_not_hd(t_token *token)
{
	return (token->type >= red_in
		&& token->type <= piped && token->type != red_hdoc);
}

bool	redirection(t_token *token)
{
	return (token->type >= red_in && token->type <= red_hdoc);
}
