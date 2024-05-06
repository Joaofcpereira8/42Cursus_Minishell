/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:57:55 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/06 12:24:55 by bbento-e         ###   ########.fr       */
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

t_env	*exp_alloc(char *args)
{
	int		i;
	int		j;
	t_env	*lst;

	i = ft_strlen_flag(args, '=');
	j = i;
	lst = malloc(sizeof(t_env));
	while (args[j] != '\0')
		j++;
	lst->type = malloc(sizeof(char) * (i + 1));
	if (j > i)
		lst->info = malloc(sizeof(char) * (j + 2));
	else
		lst->info = NULL;
	return (lst);
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
	ft_list_remove_if(&mini_shell()->env_amb_list, str, &found);
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
