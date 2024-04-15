/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:13:24 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/15 14:55:40 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	miniexport(void)
{
	int		i;
	int		j;
	int		size;
	char	*swap;

	printf("Entered miniexport with\n");
	mini_shell()->senv = mini_shell()->env;
	size = arr_size(mini_shell()->senv);
	i = 0;
	while (++i < (size - 1))
	{
		j = 0;
		if (mini_shell()->senv[i][j] == mini_shell()->senv[i + 1][j])
		{
			while ((mini_shell()->senv[i][j] || mini_shell()->senv[i + 1][j])
				   && (mini_shell()->senv[i][j] == mini_shell()->senv[i + 1][j]))
				j++;
		}
		if (mini_shell()->senv[i][j] > mini_shell()->senv[i + 1][j])
		{
			swap = mini_shell()->senv[i];
			mini_shell()->senv[i] = mini_shell()->senv[i + 1];
			mini_shell()->senv[i + 1] = swap;
			i = 0;
		}
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
		printf("%s\n", mini_shell()->senv[i]);
		i++;
	}
}
