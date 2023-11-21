/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:11 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/21 19:15:59 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	built_type(t_data *data, char **args)
{
	if(strcmp(data->comm, "echo"))
	{
		miniecho(data, args);
	}
	else if (strcmp(data->comm, "cd"))
	{
		minicd(data, args);
	}
	else if (strcmp(data->comm, "pwd"))
	{
		minipdw(data, args);
	}
	else if (strcmp(data->comm, "export"))
	{
		miniexport(data, args);
	}
	builttype_next(data, args);
}

int	builttype_next(t_data *data, char **args)
{
	if(strcmp(data->comm, "unset"))
	{
		miniunset(data, args);
	}
	else if (strcmp(data->comm, "cd"))
	{
		minienv(data, args);
	}
	else if (strcmp(data->comm, "pwd"))
	{
		miniexit(data, args);
	}
}