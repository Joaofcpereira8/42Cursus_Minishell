/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:46 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/30 18:52:22 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_minus(void)
{
	if (chdir(mini_shell()->oldpwd) == 0)
	{
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(0, 4096);
		return (printf("%s\n", mini_shell()->cwd));
	}
	else
		return (err_handler('d', NULL, 0));
}

int	mini_cd(char **args)
{
	(mini_shell()->oldpwd) = ft_get_env("OLDPWD");
	if (!args[1] && chdir(getenv("HOME")) == 0)
	{
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(0, 0);
	}
	else if (args[1][0] == '-' && !args[1][1])
		return (handle_minus());
	else if (chdir(args[1]) == 0 || ((args[1][0] == ' ' || (args[1][0] == '~'
			&& !args[1][1]) || (args[1][0] == '-' && args[1][1] == '-'
			&& !args[1][2]) || !args[1]) && chdir("/home/") == 0))
	{
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(0, 0);
	}
	else
		return (err_handler('d', args[1], 1));
	mini_shell()->exit_status = 0;
	return (0);
}
