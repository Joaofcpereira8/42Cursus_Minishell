/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:10 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/15 15:25:07 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_clean(void *value)
{
	if (value)
		free((char*)value);
	value = NULL;
}

void	clean_env(t_env *env)
{
	ft_clean(env->type);
	ft_clean(env->info);
	ft_clean(env);
}

void	clean_ast_tokens(t_a_s_tree *ast)
{
	destroy_token(ast->token);
	list_delete(ast->args);
}

void	clean_a_s_tree(t_a_s_tree *ast, void (*del)(t_a_s_tree *))
{
	if (!ast)
		return ;
	clean_a_s_tree(ast->left, del);
	clean_a_s_tree(ast->right, del);
	del(ast);
	ft_clean(ast);
}
