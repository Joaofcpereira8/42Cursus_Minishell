/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:13:24 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/18 17:52:50 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	miniexport(char **args)
{
	if (!args[1])
	{
		mini_shell()->senv = lst_to_mat(mini_shell()->env_amb_list);
		sort_export(-1, 0, arr_size(mini_shell()->senv), 3);
	}
	else if (args[1])
		export_add(args, 0, 1);
	else
		err_handler('e', args[2], 0);
}

void sort_export(int i, int j, int size, int reps)
{
	int			flag;
	(void)reps;
/*	int			a;

	a = -1;
	while (++a <= reps)
	{*/
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
				i = 0;
				flag = 1;
			}
		}
//	}
	printexp(size);
	free_array(mini_shell()->senv);
}

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

/*void export_add(char **args, int flag)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = -1;
	result = malloc(sizeof(char) * (ft_strlen(args[1]) + 3));
	while (args[1][++j] != '\0')
	{
		if (args[1][j] == '=' && flag == 0)
		{
			result[i] = '=';
			result[++i] = '"';
			flag = 1;
		}
		else
			result[i] = args[1][j];
		i++;
	}
	if (flag == 1)
		result[i] = '"';
	result[i + flag] = '\0';
	env_join(mini_shell()->senv, result);
	//ft_lstadd_back(mini_shell()->tenv);
	// free(result);
}*/

int slsh0(char *str, int i)
{
	str[i] = '\0';
	return (1);
}

t_env *exp_alloc(char *args)
{
	int		i;
	int		j;
	t_env	*lst;

	j = 0;
	i = ft_strlen_flag(args, '=');
	lst = malloc(sizeof(t_env));
	while(args[++i] != '\0')
		j++;
	lst->type = malloc(sizeof(char) * (i + 1));
	lst->info = malloc(sizeof(char) * (j + 3));
	return (lst);
}

void export_add(char **args, int flag, int a)
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
			if (args[a][j] == '=' && flag == 0 && slsh0(lst->type, i))
			{
				flag = 1;
				i = 1;
				//if(args[1][++j] != '"')
				lst->info[0] = '"';
				if(args[a][++j] == '\0')
				{
					lst->info[1] = '"';
					break;
				}
			}
			if	(flag == 0)
				lst->type[i++] = args[a][j];
			else if (flag == 1)
				lst->info[i++] = args[a][j];
		}
		if (slsh0(lst->info, i + 1) && args[a][j - 1] != '"')
			lst->info[i] = '"';
		printf("Result %s=%s\n", lst->type, lst->info);
		ft_lstadd_back(&mini_shell()->env_amb_list, ft_lstnew(lst));
		a++;
	}
}
