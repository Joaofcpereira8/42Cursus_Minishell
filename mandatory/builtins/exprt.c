/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:13:24 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/17 18:53:38 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	miniexport(char **args)
{
	if (!args[1])
	{
		printf("Entering sort_export\n");
		sort_export(0, 0, arr_size(mini_shell()->senv), 'p');
	}
	else if (args[1] && !args[2])
	{
		printf("Entering export_add\n");
		export_add(args, 0);
	}
	else
		err_handler('e', args[2], 0);
}

void	sort_export(int i, int j, int size, char fnct)
{
	int	flag;

	mini_shell()->env = lst_to_mat(mini_shell()->env_amb_list);
	while (i < (size - 1) && mini_shell()->senv[i][j])
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
		i++;
		if (i == (size - 2) && flag != 1)
		{
			flag = 1;
			i = 0;
		}
	}
	if (fnct && fnct == 'p')
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



void export_add(char **args, int flag)
{
	int		i;
	int		j;
	t_env	*lst;

	i = 0;
	j = 0;
	lst = malloc(sizeof(t_env));
	i = ft_strlen_flag(args[1], '=');
	while(args[1][++i] != '\0')
		j++;
	lst->type = malloc(sizeof(char) * i);
	lst->info = malloc(sizeof(char) * j);
	i = 0;
	j = -1;
	while (args[1][++j] != '\0')
	{
		printf("While cycle\n");
		printf("joining %c with list\n", args[1][j]);
		if (args[1][j] == '=' && flag == 0)
		{
			flag = 1;
			i = 1;
			if(args[1][++j] != '"')
				lst->info[0] = '"';
		}
		if	(flag == 0)
			lst->type[i] = args[1][j];
		else if (flag == 1)
			lst->info[i] = args[1][j];
		i++;
	}
	printf("Finished while\n");
	if (args[1][j - 1] != '"')
		lst->info[i] = '"';
	printf("Result %s=%s\n", lst->type, lst->info);
	ft_lstadd_back(&mini_shell()->env_amb_list, (void *)lst);
	list_delete(lst);
}
