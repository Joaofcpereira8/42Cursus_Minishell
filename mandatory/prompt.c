/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:22:19 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/03 17:30:37 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*get_prompt(void)
{
	char	*env;
	char	*user;

	user = ft_get_env("USER");
	env = ft_strjoin(user, "@minishell:~");
	free(user);
	user = ft_strdup(env);
	free(env);
	env = ft_strjoin(user, mini_shell()->cwd);
	free(user);
	user = ft_strjoin(env, "/$ ");
	free(env);
	return (user);
}
