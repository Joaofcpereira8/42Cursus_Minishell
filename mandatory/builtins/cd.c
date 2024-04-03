/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:46 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/03 14:08:18 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int handle_minus()
{
	if (chdir(mini_shell()->oldpwd) == 0)
	{
		//free(data->pwd);
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(0, 0);
		mini_shell()->path_change = 1;
		return (printf("%s\n", mini_shell()->cwd));
	}
	else
		return (err_handler('d', NULL));
}

int minicd(char **args)
{
	int	i;

	i = 1;
	if (args[2])
		return (err_handler('c', args[0]));
	if (args[1][0] == '-' && !args[1][1])
		return (handle_minus());
	else if (chdir(args[i]) == 0)
	{
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(0, 0);
		mini_shell()->path_change = 1;
	}
	else
		return (err_handler('d', NULL));
	free(args);
	return (0);
}