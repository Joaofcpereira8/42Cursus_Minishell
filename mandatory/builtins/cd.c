/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:46 by bbento-e          #+#    #+#             */
/*   Updated: 2024/03/22 17:53:12 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_minus(t_data *data)
{
	if (chdir(data->oldpwd) == 0)
	{
		//free(data->pwd);
		data->oldpwd = data->pwd;
		data->pwd = getcwd(0, 0);
		data->path_change = 1;
		return (printf("%s\n", data->pwd));
	}
	else
		return (err_handler('d', NULL));
}

int minicd(char **args)
{
	int	i;
    t_data *data;

    data = NULL;
    init(data);
	i = 1;
	args = ft_split(args[0], ' ');
	if (args[2])
		return (err_handler('c', args[0]));
	if (args[1][0] == '-' && !args[1][1])
		return (handle_minus(data));
	else if (chdir(args[i]) == 0)
	{
		data->oldpwd = data->pwd;
		//free(data->pwd);
		data->pwd = getcwd(0, 0);
		data->path_change = 1;
	}
	else
		return (err_handler('d', NULL));
	return (0);
}
