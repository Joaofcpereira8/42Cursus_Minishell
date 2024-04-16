/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:13:24 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/16 18:50:33 by bbento-e         ###   ########.fr       */
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
		export_add(args);
	}
	else
		err_handler('e', args[2], 0);
}

void	sort_export(int i, int j, int size, char fnct)
{
	int	flag;

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
	printf("Testing print\n");
	if (fnct && fnct == 'p')
		printexp(size);
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
/*
	(void)size;
	while (mini_shell()->env_amb_list)
	{
		printf("%s = %s\n", ((t_env *)mini_shell()->env_amb_list->content)->type, ((t_env *)mini_shell()->env_amb_list->content)->info);
		mini_shell()->env_amb_list = mini_shell()->env_amb_list->next;
	}*/
}

void	export_add(char **args)
{
	int		i;
	int		j;
	int		flag;
	char	*result;

	i = 0;
	j = 0;
	flag = 0;
	result = malloc(sizeof(char) * (ft_strlen(args[1]) + 3));
	while (args[1][j] != '\0')
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
		j++;
	}
	if (flag == 1)
	{
		result[i] = '"';
		result[i + 1] = '\0';
	}
	env_join(mini_shell()->senv, result);
	//free(result);
	printf("Reached end of export_add\n");
}
