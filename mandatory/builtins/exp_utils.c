/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:57:55 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/23 12:12:10 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	printexp(int size)
{
	int    i;

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
	str[i] = '0';
	return (1);
}


t_env	*exp_alloc(char *args)
{
	int       i;
	int       j;
	t_env  *lst;

	i = ft_strlen_flag(args, '=');
	j = i;
	lst = malloc(sizeof(t_env));
	while(args[j] != '\0')
		j++;
	lst->type = malloc(sizeof(char) * (i + 1));
	if (j > i)
		lst->info = malloc(sizeof(char) * (j + 3));
	else
		lst->info = 0;
	return (lst);
}

int exp_exists(char **args)
{
	int i;
	int j;
	found
	char *curr;

	i = 0;
	j = 0;
	while (args[i])
	{
		curr = malloc(sizeof(char) * ft_strlen_flag(args[i], '='));
		while ()
		free(curr);
	}
	return (0);
}