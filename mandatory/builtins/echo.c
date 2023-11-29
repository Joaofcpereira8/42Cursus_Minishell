/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:51 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/29 12:11:53 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	miniecho(t_data *data, char **args)
{
	int	i;
	int nl;

	/*args[1] = " ";
	args[2] = "hello ";
	args[3] = "world";*/
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
		i++;
	}
	if (nl == 0)
		printf("%%\t");
	else
		printf("\n");
	wait(NULL);
	return (0);
}