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

int built_type(t_data *data, char **args)
{
	if(ft_strncmp(data->comm, "echo", 4) == 0)
	{
		miniecho(data, args);
	}
	else if (ft_strncmp(data->comm, "cd", 2) == 0)
	{
		minicd(data, args);
	}
	else if (ft_strncmp(data->comm, "pwd", 3) == 0)
	{
		minipdw(data);
	}
	else if (ft_strncmp(data->comm, "export", 6) == 0)
	{
		miniexport(data, args);
	}
	else
		return (built_type_next(data, args));
	return (0);
}

int	built_type_next(t_data *data, char **args)
{
	if(ft_strncmp(data->comm, "unset", 5) == 0)
	{
		miniunset(data, args);
	}
	else if (ft_strncmp(data->comm, "env", 3) == 0)
	{
		minienv(mini_shell()->env_amb_list);
	}
	else if (ft_strncmp(data->comm, "exit", 4) == 0)
	{
		miniexit(data, args);
	}
	else
		return (-1);
	return (0);
}
