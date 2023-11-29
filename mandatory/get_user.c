/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/29 11:25:32 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*vai buscar o user e o lugar onde se encontra nas
variaveis de ambiente*/

void	ft_get_env(t_env_detail *envi)
{
	char	*env;
	if (!envi)
		return ;
	envi->user = getenv("USER");
	envi->sesh = "minishell";
	// envi->path_env = getenv("PATH");
	env = ft_strjoin(env, envi->user);
	env = ft_strjoin(env, "@");
	env = ft_strjoin(env, envi->sesh);
	envi->prompt = ft_strjoin(env, ":~/$ ");
	free(env);
}
