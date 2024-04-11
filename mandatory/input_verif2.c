/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verif2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:23:10 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/11 12:14:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

bool	input_analysis(void)
{
	t_token *next;
	int		num_of_pipes;
	int		num_of_commands;

	num_of_commands = 1;
	num_of_pipes = 0;
	scanner(RESET);
	if (pipe_or_redir(scanner(READ)))
		return(pars_error('s', 2));
	while (scanner(READ))
	{
		next = scanner(AFTER);
		if (redirection(scanner(READ)) && (!next || pipe_or_redir(next)))
			return (pars_error('r', 2));
		if (scanner(READ)->type == piped)
		{
			num_of_pipes++;
			if (next && !pipe_or_redir(next))
				num_of_commands++;
		}
	scanner(NEXT);
	}
	if (num_of_pipes >= num_of_commands)
		return(pars_error('p', 2));
	return (true);
}

t_token	*scanner(t_operations operations)
{
	static t_list	*current = NULL;
	if (operations == READ && current)
		return (current->content);
	else if (operations == RESET)
		current = mini_shell()->env_token;
	else if (operations == NEXT)
		current =current->next;
	else if (operations == AFTER && current->next)
		return (current->next->content);
	return (NULL);
}

bool	pipe_or_redir(t_token *token)
{
	return (token->type >= red_in && token->type <= piped);
}

bool	redirection(t_token *token)
{
	return(token->type >= red_in && token->type <= red_hdoc);
}


bool	is_command(t_token *token)
{
	int	i;

	i = -1;
	if (token->str[0])
	{
		if (token->str[0] == '=' || token->str[ft_strlen(token->str) - 1] == '=')
		{
			pars_error('b', 1);
			return (false);
		}
	}
	while (token->str[++i])
	{
		if (token->str[i] == '=')
		{
			add_env_vars(&mini_shell()->temp_env, token->str);
			return (true);
		}
	}
	return (false);
}
