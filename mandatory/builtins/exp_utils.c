/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:57:55 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/06 14:47:46 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	printexp(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("declare -x ");
		printf("%s\n", mini_shell()->senv[i]);
		i++;
	}
}

int	slsh0(char *str, int i)
{
	str[i] = '\0';
	return (1);
}

int	add_quo(t_env **lst)
{
	(*lst)->info[1] = '"';
	return (1);
}

bool	exp_exists(char *args)
{
	int		j;
	char	*str;
	bool	found;

	found = false;
	j = -1;
	str = malloc(sizeof(char) * ft_strlen_flag(args, '=') + 1);
	while (args[++j] && args[j] != '=')
		str[j] = args[j];
	str[j] = '\0';
	found = env_unset(str);
	free(str);
	if (found == true)
		export_add(args, 0, 0, -1);
	mini_shell()->exit_status = 0;
	return (found);
}

void	ft_list_remove_if(t_list **list, char *args, bool *found)
{
	t_list	*cur;
	t_env	*env;

	if (list == NULL || *list == NULL)
		return ;
	cur = *list;
	env = cur->content;
	if (ft_strcmp(env->type, args) == 0)
	{
		*list = cur->next;
		free(cur);
		ft_list_remove_if(list, args, found);
		if (found != NULL)
			*found = true;
	}
	else
	{
		cur = *list;
		ft_list_remove_if(&cur->next, args, found);
	}
}
