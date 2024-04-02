/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:11 by bbento-e          #+#    #+#             */
/*   Updated: 2024/03/22 17:52:19 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int built_type(char **args)
{
	if(!builtin_verif(args[0]))
		exec_command(args);
	else if(ft_strncmp(mini_shell()->input, "echo", 4) == 0)
	{
		miniecho(args);
	}
	else if (ft_strncmp(mini_shell()->input, "cd", 2) == 0)
	{
		minicd(args);
	}
	else if (ft_strncmp(mini_shell()->input, "pwd", 3) == 0)
	{
		//minipdw(data);
		// printf("%s\n", mini_shell()->cwd);
	}
	else if (ft_strncmp(mini_shell()->input, "export", 6) == 0)
	{
		miniexport(args);
	}
	else
		return (built_type_next(args));
	return (0);
}

int built_type_next(char **args)
{
	if(ft_strncmp(mini_shell()->input, "unset", 5) == 0)
	{
		miniunset(args);
	}
	else if (ft_strncmp(mini_shell()->input, "env", 3) == 0)
	{
		minienv(mini_shell()->env_amb_list);
	}
	else if (ft_strncmp(mini_shell()->input, "exit", 4) == 0)
	{
		miniexit(args);
	}
	else
		return (-1);
	return (0);
}
