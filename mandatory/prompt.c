/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:22:19 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/30 14:20:42 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*get_prompt(void)
{
	char	*env;
	char	*user;
	char	*path;
	int		i;
	int		a;

	i = ft_strlen(mini_shell()->cwd);
	user = ft_get_env("USER");
	a = ft_strlen(user);
	path = ft_substr(ft_strnstr(mini_shell()->cwd, user, i), a, i);
	env = ft_get_env("USER");
	env = ft_strjoin(env, "@minishell:~");
	env = ft_strjoin(env, path);
	env = ft_strjoin(env, "/$ ");
	free (user);
	return (env);
}
