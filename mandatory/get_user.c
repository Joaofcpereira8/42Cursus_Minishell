/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/27 18:03:09 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*vai buscar o user e o lugar onde se encontra nas
variaveis de ambiente*/

char	*get_path(void)
{
	char	*result;
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = getcwd(0, 0);
	while (tmp[i])
	{
		if (tmp[i] == 47)
			j++;
		if (j == 5)
			break ;
		i++;
	}
	result = ft_strdup(tmp + i);
	free(tmp);
	return (result);
}

void	get_session(t_env_detail *envi)
{
	int i;

	i = 0;
	char *mngr = getenv("SESSION_MANAGER");
	// Find the position of '@'
	char *at = ft_strchr(mngr, '@');

	// Find the position of ':'
	char *col = ft_strchr(mngr, ':');

	// Check if both '@' and ':' are found
	if (at != NULL && col != NULL && at < col)
	{
		size_t len = col - (at + 1);
		char trim[len + 1];
		strncpy(trim, at + 1, len);
		trim[len] = '\0';
		envi->sesh = trim;
	}
}

char	*ft_get_env(t_env_detail *envi)
{
	char	*env;
	if (!envi)
		return -1;
	envi->user = getenv("USER");
	envi->sesh = "minishell";
	// envi->path_env = getenv("PATH");
	env = ft_strjoin(env, envi->user);
	env = ft_strjoin(env, "@");
	env = ft_strjoin(env, envi->sesh);
	env = ft_strjoin(env, ":~/$ ");
	env = ft_strjoin(env, ":~/$ ");
	return (env);
}

char	p_finder(t_data *data)
{
	data->cwd = get_path();
	return(0);
}
