/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:32 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/21 19:09:13 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	miniecho(t_data *data, char **args)
{
	(void)data;
	if(args[0][0] == '-' && args[0][1] == 'n')
	{
		// -n     do not output the trailing newline
	}
}