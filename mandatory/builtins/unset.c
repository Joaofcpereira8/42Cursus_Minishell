/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:34:37 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/07 19:06:38 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	miniunset(char **args)
{
	int		i;

	i = 0;
	while (args[++i])
		env_unset(args[i]);
	mini_shell()->close_p = -1;
	mini_shell()->exit_status = 0;
	return (0);
}

int	env_unset(char *args)
{
	t_list	**head;
	t_list	*temp;
	t_list	*prev;
	t_env	*env;

	head = &mini_shell()->env_amb_list;
	temp = *head;
	prev = NULL;
	while (temp != NULL)
	{
		env = (t_env *)temp->content;
		if (ft_strcmp(env->type, args) == 0)
		{
			if (prev == NULL)
				*head = temp->next;
			else
				prev->next = temp->next;
			free_env(&env);
			free(temp);
			return (0);
		}
		prev = temp;
		temp = temp->next;
	}
	return (-1);
}
