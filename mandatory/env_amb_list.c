/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_amb_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:13:59 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/03 15:13:59 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_list	*envlist(char **env)
{
	t_list	*envlist;
	int		i;

	i = mat_env_list(env);
	envlist = NULL;
	while(--i >= 0)
		envlist = add_env_vars();
	return(envlist);
}

int	mat_env_list(char **mat)
{
	int	i;

	if(!mat)
		return(-1);
	while(mat[i])
		i++;
	return(i);
}

void	add_env_vars(int **envlist, char *container)
{
	int		i;
	char	*type;
	char	*info;
	t_env	*env;

	i = ft_strlen_flag(container, '=');
	type = ft_substr(container, 0, i);
	info = ft_strdup(container + i + 1);
	//ver env
	if(env)
	{
		free(type);
		free(info);
		env->info = info;
	}
	else
		ft_lstadd_front(envlist, ft_lstnew(new_env(type, info)));
}