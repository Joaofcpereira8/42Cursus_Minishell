/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:34:51 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/06 22:34:52 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*rm_quotes(char *arg)
{
	size_t	len;
	char	*new_arg;

	len = strlen(arg);
	if (len > 1 && ((arg[0] == '"' && arg[len - 1] == '"')
		|| (arg[0] == '\'' && arg[len - 1] == '\'')))
	{
		new_arg = ft_substr(arg, 1, len - 2);
		free(arg);  // assuming arg was dynamically allocated
		return (new_arg);
	}
	return (arg);
}