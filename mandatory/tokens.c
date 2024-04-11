/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:38:01 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/11 12:13:58 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_token *new_token(char *str, t_meta_tok type, bool join)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = str;
	token->type = type;
	token->can_join = join;
	return (token);
}

t_token	*copy_token(t_token *token)
{
	t_token	*duplicate;

	duplicate = new_token(ft_strdup(token->str), token->type, token->can_join);
	if (!duplicate)
		return (NULL);
	return (duplicate);
}

int	conv_to_token(char *str, t_meta_tok type, bool joinable)
{
	t_token	*token;

	token = new_token(str, type, joinable);
	if (!token || !str)
		return (0);
	ft_lstadd_back(&mini_shell()->env_token, ft_lstnew(token));
	return ((int)ft_strlen(str));
}

void	destroy_token(t_token *token)
{
	if (!token)
		return ;
	ft_clean(token->str);
	ft_clean(token);
}
