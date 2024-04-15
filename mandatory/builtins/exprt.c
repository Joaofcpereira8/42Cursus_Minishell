/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:13:24 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/15 18:43:08 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void miniexport(char **args)
{
	if (!args[1])
		sort_export(0, 0, arr_size(mini_shell()->senv), 's');
	else if (args[1] && !args[2])
		export_add(args);
	else
		err_handler('e', args[2], 127);
}

void sort_export(int i, int j, int size, char fnct)
{
	int		flag;

	// mini_shell()->senv = mini_shell()->env;
	while (i < (size - 1))
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
	if(fnct && fnct == 'p')
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
}

void export_add(char **args)
{
	int	i;
	char *result;

	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(args[1]) + 3));
	while (args[1][i])
	{
		result[i] = args[1][i];
		if (args[1][i] == '=')
		{
			result[i + 1] = '"';
			i += 2;
		}
		i++;
	}
	result[i] = '"';
	result[i] = '\0';
	mini_shell()->senv;
	free(result);
}
