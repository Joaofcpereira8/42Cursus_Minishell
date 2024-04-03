/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:10 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/19 16:36:43 by jofilipe         ###   ########.fr       */
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
	ft_clean(env->type);
	ft_clean(env);
}

void	ft_free_all(bool del)
{
	ft_clean(mini_shell()->input);
	ft_clean(mini_shell()->prompt);
	//free da arvore sintaxe
	list_delete(mini_shell()->pipes);
	ft_lstclear(&mini_shell()->env_token, (void (*)(void *))destroy_token);
	mini_shell()->env_token = NULL;
	mini_shell()->pipes = NULL;
	mini_shell()->prompt = NULL;
	mini_shell()->cmd_num = 0;
	if (del)
	{
		ft_clean(mini_shell()->cwd);
		list_delete(mini_shell()->path);
		list_delete(mini_shell()->env);
		ft_lstclear(&mini_shell()->env_amb_list, (void (*)(void *))clean_env);
		ft_lstclear(&mini_shell()->temp_env, (void (*)(void *))clean_env);
	}
}