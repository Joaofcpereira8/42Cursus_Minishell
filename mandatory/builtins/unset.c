/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:34:37 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/06 12:25:24 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	miniunset(char **args)
{
	t_list **head;
	t_list *temp;
	t_list *prev;

	head = &mini_shell()->env_amb_list;
	temp = *head;
	prev = NULL;
	while (temp != NULL)
	{
		t_env *env = (t_env *)temp->content;
		if (ft_strcmp(env->type, args[1]) == 0) {
			if (prev == NULL)
				*head = temp->next;
			else
				prev->next = temp->next;
			free(env->type);
			free(env->info);
			free(env);
			free(temp);
			return (0);
		}
		prev = temp;
		temp = temp->next;
	}
	return (0);
}
