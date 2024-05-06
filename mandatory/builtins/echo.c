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

	i = 2;
	size = arr_size(args);
	while (i < size)
	{
		if (args[1] && args[1][0] == '-' && args[1][1] == 'n' && !args[1][2])
		{
			if (args[i][0] == '-' && (args[i][1] == 'n' || args[i][1] == 'e'
				|| args[i][1] == 'E'))
				return (-1);
		}
		i++;
	}
	return (0);
}

int	miniecho(char **args)
{
	int	i;
	int	nl;

	if (echo_valid(args) == -1)
		return (err_handler('c', mini_shell()->input, 0));
	nl = 1;
	i = 1;
	if (args[1] && args[1][0] == '-' && args[1][1] == 'n' && !args[1][2])
	{
		nl = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (nl == 1)
		printf("\n");
	mini_shell()->exit_status = 0;
	return (0);
}
