/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:46 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/29 18:54:17 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	minicd(t_data *data, char **args)
{
	int	i;

	i = 1;
	if(args[2])
		return (err_handler('c', args[0]));
	if(chdir(args[i]) == 0)
	{
		free(data->pwd);
		data->pwd = getcwd(0, 0);
	}
	else
		return (err_handler('d', NULL));
	return (0);
}