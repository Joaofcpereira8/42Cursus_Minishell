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

void	ft_clean(void *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
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

void	ft_free(void)
{
	ft_clean(mini_shell()->input);
	ft_clean(mini_shell()->prompt);
	clean_a_s_tree(mini_shell()->ast, clean_ast_tokens);
	list_delete(mini_shell()->pipes);
	ft_lstclear(&mini_shell()->env_token, (void (*)(void *))destroy_token);
	mini_shell()->env_token = NULL;
	mini_shell()->pipes = NULL;
	mini_shell()->prompt = NULL;
	mini_shell()->ast = NULL;
	mini_shell()->cmd_num = 0;
}

void	ft_free_all(void)
{
	ft_clean(mini_shell()->cwd);
	list_delete(mini_shell()->path);
	list_delete(mini_shell()->env);
	ft_lstclear(&mini_shell()->env_amb_list, (void (*)(void *))clean_env);
	ft_lstclear(&mini_shell()->temp_env, (void (*)(void *))clean_env);
	exit(mini_shell()->exit_status);
}