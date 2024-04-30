/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:54:00 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/30 15:03:03 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	miniexport(char **args, int flag)
{
	int		i;
	int		j;

	i = 0;
	if (!args[1])
	{
		mini_shell()->senv = lst_to_mat(mini_shell()->env_amb_list);
		sort_export(-1, 0, arr_size(mini_shell()->senv), 3);
		free_array(mini_shell()->senv);
	}
	else
	{
		while (args[++i])
		{
			j = -1;
			flag = 0;
			while (args[i][++j])
			{
				if (args[i][j] == '=' && j > 0)
					break ;
				if (ft_isalpha(args[i][j]) != 1 && args[i][j] != '_')
				{
					flag = err_handler('e', &args[i][j], 1);
					break ;
				}
			}
			if (args[1] && flag != -1)
				if (exp_exists(args[i]) == false)
					export_add(args[i], 0);
		}
	}

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

void export_add(char *args, int flag)
{
	int		i;
	int		j;
	t_env	*lst;

	lst = exp_alloc(args);
	i = 0;
	j = -1;
	flag = 0;
	while (args[++j] != '\0')
	{
		if (args[j] != ' ')
		{
			if (args[j] == '=' && flag == 0 )
			{
				lst->type[i] = '\0';
				flag = 1;
				i = 1;
				lst->info[0] = '"';
				if(args[++j] == '\0')
				{
					lst->info[1] = '"';
					break;
				}
			}
			if (flag == 0)
				lst->type[i++] = args[j];
			else if (flag == 1)
				lst->info[i++] = args[j];
		}
	}
	if (flag == 0)
		lst->type[i] = '\0';
	if (args[j - 1] != '"' && flag == 1 && slsh0(lst->info, i))
	{
		lst->info[i] = '"';
		lst->info[i + 1] = '\0';
	}
	ft_lstadd_back(&mini_shell()->env_amb_list, ft_lstnew(lst));
}