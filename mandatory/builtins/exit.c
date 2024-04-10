/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:12:02 by bbento-e          #+#    #+#             */
/*   Updated: 2024/03/21 10:46:39 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void miniexit(char **args)
{
	int	i;

	i = -1;
	if (**args == 0)
	{
		printf("exit\n");
		ft_free();
		ft_free_all();
	}
	else
	{
		while (ft_isdigit(args[1][++i]))
		{
			mini_shell()->exit_status = **args % 256;
			printf("exit\n");
			printf("%i\n", mini_shell()->exit_status);
			ft_free();
			ft_free_all();
		}
	}

	//exit(mini_shell()->exit_status);
}
