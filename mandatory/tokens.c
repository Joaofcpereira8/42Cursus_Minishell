/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:38:01 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/25 14:24:20 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_token *new_token(char *str, t_meta_tok type, bool join)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(*token));
	if (!token)
		return (NULL);
	token->str = str;
	token->type = type;
    token->can_join = join;
	return (token);
}

int conv_to_token(char *str, t_meta_tok type, bool joinable)
{
	t_token	*token;

	token = new_token(str, type, joinable);
	if (!str || !type)
		return (0);
	ft_lstadd_back(&mini_shell()->env_token, ft_lstnew(token));
	return (ft_strlen(str));
}