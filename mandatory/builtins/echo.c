/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:51 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/08 18:18:11 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int miniecho(char **args)
{
	int	i;
	int nl;

	if ((!mini_shell()->input[5] && !mini_shell()->input[6]) || mini_shell()->input[5] == ' ')
	{
		printf("\n");
		return (-1);
	}
	nl = 1;
	i = 1;
	if(args[1][0] && args[1][0] == '-' && args[1][1] == 'n')
	{
		nl = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if(args[i + 1])
			printf(" ");
		i++;
	}
//	if (nl == 0)
//		printf("%%");
//	else
//		printf("\n");
	if (nl != 0)
		printf("\n");
	wait(NULL);
	return (0);
}
