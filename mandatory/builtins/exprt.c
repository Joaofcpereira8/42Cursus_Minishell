/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:13:24 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/10 18:55:20 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	miniexport(void)
{
	int		i;
	int		size;
	char	*swap;

	printf("Entered miniexport\n");
	size = arr_size(mini_shell()->env);
	i = 0;
	while (i < (size - 1))
	{
		if (mini_shell()->env[i][0] == mini_shell()->env[i + 1][0])
		{
			while ((mini_shell()->env[i][0] || mini_shell()->env[i + 1][0])
				   && (mini_shell()->env[i][0] == mini_shell()->env[i + 1][0]))
				i++;
		}
		if (mini_shell()->env[i][0] > mini_shell()->env[i + 1][0])
		{
			swap = mini_shell()->env[i];
			mini_shell()->env[i] = mini_shell()->env[i + 1];
			mini_shell()->env[i + 1] = swap;
			i = 0;
		}
		i++;
	}
	printf("Sorted export\n");
	printexp(size);
	return (0);
}

void	printexp(int size)
{
	int	i;

	i = 0;
	printf("Started printing export\n");
	while (i < size)
	{
		printf("declare -x ");
		printf("%s\n", mini_shell()->env[i]);
		i++;
	}
}
