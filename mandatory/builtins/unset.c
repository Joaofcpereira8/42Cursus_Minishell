/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:34:37 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/23 15:29:13 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	miniunset(char **args)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (args[++i])
	{
		j = -1;
		str = malloc(sizeof(char) * ft_strlen(args[i]));
		while (args[i][++j])
			str[j] = args[i][j];
		str[j] = '\0';
		ft_list_remove_if(&ms_env, str, NULL);
		free(str);
	}
	return (0);
}
