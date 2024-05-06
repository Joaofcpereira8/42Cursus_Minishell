/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:12:02 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/18 11:03:14 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	mini_exit2(char **args)
{
	mini_shell()->exit_status = ft_atoll(args[1]) % 256;
	printf("exit\n");
	ft_free();
	ft_free_all();
}

void	mini_exit3(char **args)
{
	printf("exit\n");
	printf("minishell: %s: numeric argument required\n", args[1]);
	mini_shell()->exit_status = 2;
	ft_free();
	ft_free_all();
}

void	miniexit(char **args)
{
	if (!args[1])
	{
		printf("exit\n");
		ft_free();
		ft_free_all();
	}
	if (args[2])
	{
		if (ft_islonglong(args[1]))
		{
			printf("exit\n");
			printf("minishell: exit: too many arguments\n");
			mini_shell()->exit_status = 1;
			return ;
		}
		else if (ft_atoll(args[1]) != -1 || ft_strcmp(args[1], "-1") == 0)
			mini_exit3(args);
	}
	if (ft_atoll(args[1]) != -1 || ft_strcmp(args[1], "-1") == 0)
		mini_exit2(args);
	else
		mini_exit3(args);
}
