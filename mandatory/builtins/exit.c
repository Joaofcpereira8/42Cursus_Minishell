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
	if (!args[0])
	{
		printf("exit\n");
		ft_free();
		ft_free_all();
	}
	if (args[2])
	{
		printf("minishell: exit: too many arguments\n");
		return ;
	}
	if (ft_atoi(args[1]) != -1 || ft_strcmp(args[1], "-1") == 0)
	{
		mini_shell()->exit_status = ft_atoi(args[1]) % 256;
		printf("exit\n");
		printf("%i\n", mini_shell()->exit_status);
		ft_free();
		ft_free_all();
	}
	else
	{
		printf("exit: %s: numeric argument required\n", args[1]);
		mini_shell()->exit_status = 2;
		ft_free();
		ft_free_all();
	}
}
