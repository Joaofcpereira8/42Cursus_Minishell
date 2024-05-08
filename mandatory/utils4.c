/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:34:51 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/08 15:36:04 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*rm_quotes(char *arg)
{
	size_t	len;
	char	*new_arg;

	len = ft_strlen(arg);
	if (len > 1 && ((arg[0] == '"' && arg[len - 1] == '"')
			|| (arg[0] == '\'' && arg[len - 1] == '\'')))
	{
		new_arg = ft_substr(arg, 1, len - 2);
		free(arg);
		return (new_arg);
	}
	return (arg);
}

void	ft_get_oldpwd(void)
{
	char	*oldpwd;

	oldpwd = NULL;
	if (!oldpwd)
		oldpwd = ft_get_env("OLDPWD");
	if (!mini_shell()->oldpwd)
		mini_shell()->oldpwd = ft_strdup(oldpwd);
	ft_clean(oldpwd);
}
