/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:56:20 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/07 15:32:43 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_free(void)
{
	ft_clean(mini_shell()->input);
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
	rl_clear_history();
	ft_clean(mini_shell()->oldpwd);
	ft_clean(mini_shell()->cwd);
	list_delete(mini_shell()->path);
	list_delete(mini_shell()->env);
	ft_lstclear(&mini_shell()->env_amb_list, (void (*)(void *))clean_env);
	ft_lstclear(&mini_shell()->temp_env, (void (*)(void *))clean_env);
	exit(mini_shell()->exit_status);
}
