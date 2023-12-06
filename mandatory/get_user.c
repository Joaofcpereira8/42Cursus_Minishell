/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/12/06 15:58:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*vai buscar o user e o lugar onde se encontra nas
variaveis de ambiente*/

void	ft_get_env(t_env_detail *envi)
{
	char	*env;
	int i;

	i = ft_strlen(getcwd(0, 0));
	if (!envi)
		return ;
	envi->user = getenv("USER");
	envi->sesh = "minishell";
	// envi->path_env = getenv("PATH");
	env = ft_strjoin(env, envi->user);
	env = ft_strjoin(env, "@");
	env = ft_strjoin(env, envi->sesh);
	env = ft_strjoin(env, ":~");
	env = ft_strjoin(env, ft_strnstr(getcwd(0, 0), envi->user, i));
	envi->prompt = ft_strjoin(env, "/$ ");
	free(env);
}