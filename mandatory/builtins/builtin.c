/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:11 by bbento-e          #+#    #+#             */
/*   Updated: 2024/05/06 14:35:37 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	built_type(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		args[i] = rm_quotes(args[i]);
		i++;
	}
	if (!builtin_verif(args[0]))
		exec_command(args);
	else if (ft_strncmp(args[0], "echo", 4) == 0)
		miniecho(args);
	else if (ft_strncmp(args[0], "cd", 2) == 0)
		mini_cd(args);
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		minipdw();
	else if (ft_strncmp(args[0], "export", 6) == 0)
		miniexport(args, 0, 0, 0);
	else
		return (built_type_next(args));
	return (0);
}

int	built_type_next(char **args)
{
	if (ft_strncmp(args[0], "unset", 5) == 0)
		miniunset(args);
	else if (ft_strncmp(args[0], "env", 3) == 0)
		minienv(mini_shell()->env_amb_list);
	else if (ft_strncmp(args[0], "exit", 4) == 0)
		miniexit(args);
	else
		return (-1);
	return (0);
}
