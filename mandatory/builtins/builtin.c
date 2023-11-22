/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:11 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/22 17:21:53 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	built_type(t_data *data, char **args)
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
		return (builttype_next(data, args));
	return (0);
}

int	builttype_next(t_data *data, char **args)
{
	if(ft_strncmp(data->comm, "unset", 5) == 0)
	{
		miniunset(data, args);
	}
	else if (ft_strncmp(data->comm, "env", 3) == 0)
	{
		minienv(data, args);
	}
	else if (ft_strncmp(data->comm, "exit", 4) == 0)
	{
		miniexit(data, args);
	}
	else
		return (-1);
	return (0);
}