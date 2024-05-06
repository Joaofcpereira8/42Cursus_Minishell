/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:34:37 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/06 12:25:24 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	miniunset(char **args)
{
	int		i;
	char	*str;

	i = 0;
	while (args[++i])
	{
		str = ft_strdup(args[i]);
		ft_list_remove_if(&mini_shell()->env_amb_list, str, NULL);
		free(str);
	}
	return (0);
}
