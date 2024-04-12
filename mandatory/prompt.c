/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:22:19 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/12 15:22:20 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*get_prompt(void)
{
	char	*env;
	char	*user;
	int		i;
	int		a;

	env = NULL;
	user = NULL;
	i = ft_strlen(getcwd(0, 0));
	user = ft_get_env("USER");
	a =  ft_strlen(user);
	env = ft_strjoin(env, user);
	env = ft_strjoin(env, "@");
	env = ft_strjoin(env, "minishell");
	env = ft_strjoin(env, ":~");
	env = ft_strjoin(env, ft_substr(ft_strnstr(getcwd(0, 0), user, i), a, i));
	env = ft_strjoin(env, "/$ ");
	free(user);
	return (env);
}