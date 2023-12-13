/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/12/13 16:25:10 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*vai buscar o user e o lugar onde se encontra nas
variaveis de ambiente*/

void	ft_get_env(t_env_detail *envi)
{
	char	*env = NULL;
	int		i;
	int		a;

	i = ft_strlen(getcwd(0, 0));
	if (!envi)
		return ;
	// data->path_change = 0;
	envi->user = getenv("USER");
	a =  ft_strlen(envi->user);
	envi->sesh = "minishell";
	env = ft_strjoin(env, envi->user);
	env = ft_strjoin(env, "@");
	env = ft_strjoin(env, envi->sesh);
	env = ft_strjoin(env, ":~");
	env = ft_strjoin(env, ft_substr(ft_strnstr(getcwd(0, 0), envi->user, i), a, i));
	envi->prompt = ft_strjoin(env, "/$ ");
	free(env);
}
