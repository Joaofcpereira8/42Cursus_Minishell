/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:55:57 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:25 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_a_s_tree	*ast_new_token(t_token *token)
{
	t_a_s_tree	*node;

	node = ft_calloc(1, sizeof(t_a_s_tree));
	if (!node)
		return (NULL);
	node->token = token;
	node->args = ft_calloc(1, sizeof(char *));
	return (node);
}

void	ast_insert(t_a_s_tree **ast, t_a_s_tree *node, bool left)
{
	if (*ast && left)
		(*ast)->left = node;
	else if (*ast && !left)
		(*ast)->right = node;
	else
		*ast = node;
}
