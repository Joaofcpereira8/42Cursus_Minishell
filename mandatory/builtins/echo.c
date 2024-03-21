/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:51 by bbento-e          #+#    #+#             */
/*   Updated: 2024/03/21 12:16:36 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	miniecho(t_data *data, char **args)
{
	int	i;
	int nl;

	if (!data->comm[5] && !data->comm[6])
	{
		printf("\n");
		return (-1);
	}

	args = ft_split(args[0], ' ');
	nl = 1;
	i = 1;
	(void)data;
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
	if (nl == 0)
		printf("%%");
	else
		printf("\n");
	wait(NULL);
	return (0);
}
