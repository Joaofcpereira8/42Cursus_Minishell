/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:46 by bbento-e          #+#    #+#             */
/*   Updated: 2023/12/05 18:45:27 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_minus(t_data *data)
{
	char	*tmp;

	if (chdir(data->oldpwd) == 0)
	{
		tmp = data->pwd;
		free(data->pwd);
		data->pwd = data->oldpwd;
		data->oldpwd = tmp;
		free(tmp);
	}
	else
		return printf("wtf\n");//(err_handler('d', NULL));
	return (0);
}

int	minicd(t_data *data, char **args)
{
	int	i;

	i = 1;
	args = ft_split(args[0], ' ');
	if (args[2])
			return (err_handler('c', args[0]));
	if(args[1][0] == '-')
		return (handle_minus(data));
	else if (chdir(args[i]) == 0)
	{
		data->oldpwd = data->pwd;
		free(data->pwd);
		data->pwd = getcwd(0, 0);
	}
	else
		return (err_handler('d', NULL));
	return (0);
}
