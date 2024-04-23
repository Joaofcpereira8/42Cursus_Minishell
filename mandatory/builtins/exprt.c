/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:54:00 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/23 15:07:53 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	miniexport(char **args)
{
	int		i;
	int		j;

	i = 0;
	while (args[i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (args[i][j] == '=' && args[i][j + 1])
				break ;
			if (ft_isalpha(args[i][j]) != 1 && args[i][j] != '_')
				return ((void)(err_handler('e', &args[i][j], 1)));
		}
		i++;
	}
	if (!args[1])
	{
		mini_shell()->senv = lst_to_mat(mini_shell()->env_amb_list);
		sort_export(-1, 0, arr_size(mini_shell()->senv), 3);
		free_array(mini_shell()->senv);
	}
	else if (args[1])
		if (exp_exists(args) == false)
			export_add(args, 0, 1);
}

void	sort_export(int i, int j, int size, int reps)
{
	int		flag;
	int		a;

	a = -1;
	while (++a <= reps)
	{
		while (++i < (size - 1) && mini_shell()->senv[i][j])
		{
			j = 0;
			if (mini_shell()->senv[i][j] == mini_shell()->senv[i + 1][j])
			{
				while ((mini_shell()->senv[i][j] || mini_shell()->senv[i + 1][j])
					   && (mini_shell()->senv[i][j] == mini_shell()->senv[i + 1][j]))
					j++;
			}
			if ((mini_shell()->senv[i][j] > mini_shell()->senv[i + 1][j]) || i == 0)
				i = ft_swap_env(mini_shell()->senv[i], i);
			if (i == (size - 2) && flag != 1)
			{
				i = -1;
				flag = 1;
			}
		}
	}
	printexp(size);
}

void	export_add(char **args, int flag, int a)
{
	int		i;
	int		j;
	t_env	*lst;

	while (args[a])
	{
		lst = exp_alloc(args[a]);
		i = 0;
		j = -1;
		flag = 0;
		while (args[a][++j] != '\0')
		{
			if (args[a][j] != ' ')
			{
				if (args[a][j] == '=' && flag == 0 )//&& slsh0(lst->type, i))
				{
					lst->type[i] = '\0';
					flag = 1;
					i = 1;
					lst->info[0] = '"';
					if(args[a][++j] == '\0')
					{
						lst->info[1] = '"';
						break;
					}
				}
				if (flag == 0)
					lst->type[i++] = args[a][j];
				else if (flag == 1)
					lst->info[i++] = args[a][j];
			}
		}
		if (flag == 0)
			lst->type[i] = '\0';
		if (args[a][j - 1] != '"' && flag == 1 && slsh0(lst->info, i))
		{
			lst->info[i] = '"';
			lst->info[i + 1] = '\0';
		}
		printf("Result %s=%s\n", lst->type, lst->info);
		ft_lstadd_back(&mini_shell()->env_amb_list, ft_lstnew(lst));
		a++;
	}
}