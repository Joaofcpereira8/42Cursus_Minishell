/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:51 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/06 17:55:30 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	echo_valid(char **args)
{
	int	i;
	int	size;
	int	j;

	i = 1;
	size = arr_size(args);
	while (i < size)
	{
		if (args[i][0] == '-' && args[i][1] == 'n')
		{
			j = 2;
			while (args[i][j] != '\0')
			{
				if (args[i][j] != 'n')
					return (i);  // Return the index of the first non-valid -n flag
				j++;
			}
		}
		else
			return (i);  // Return the index of the first non-flag argument
		i++;
	}
	return (size);  // If all are valid -n flags, start printing from here (effectively nothing to print)
}

int	miniecho(char **args)
{
	int	i;
	int	nl;
	int	start_index;

	nl = 1;  // Assume we need a newline by default
	start_index = echo_valid(args);
	// If the first valid flag is a no-newline flag, suppress the newline
	if (start_index > 1 && args[1][0] == '-' && args[1][1] == 'n')
		nl = 0;
	i = start_index;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");  // Add space between words
		i++;
	}
	if (nl)
		printf("\n");
	mini_shell()->exit_status = 0;
	return (0);
}
