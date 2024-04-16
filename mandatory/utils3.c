/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:57:23 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/16 15:58:54 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	arr_size(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_skp(char *str, char *c)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(c, str[i]))
		i++;
	return (i);
}

int	ft_swap_env(char *swap, int i)
{
	swap = mini_shell()->senv[i];
	mini_shell()->senv[i] = mini_shell()->senv[i + 1];
	mini_shell()->senv[i + 1] = swap;
	return (0);
}

void	env_join(char **arr1, char *str)
{
	int		size;
	int		i;
	char	**final;

	printf("Entering env_join\n");
	i = 0;
	size = arr_size(arr1) + 1;
	final = malloc(sizeof(char *) * size);
	while (i <= size && arr1[i])
	{
		final[i] = arr1[i];
		i++;
	}
	final[i] = str;
	mini_shell()->senv = malloc(sizeof(char *) * size);
	mini_shell()->senv = final;
	printf("Joined env with str\n");
}
