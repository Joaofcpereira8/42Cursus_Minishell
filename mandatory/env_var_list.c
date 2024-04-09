/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:13:59 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/09 12:32:20 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_list	*envlist(char **env)
{
	t_list	*envlist;
	int		i;

	i = sz_env_list(env);
	envlist = NULL;
	while (--i >= 0)
		add_env_vars(&envlist, env[i]);
	return (envlist);
}

void	add_env_vars(t_list **envlist, char *container)
{
	int		i;
	char	*type;
	char	*info;
	t_env	*env;

	i = ft_strlen_flag(container, '=');
	type = ft_substr(container, 0, i);
	info = ft_strdup(container + i + 1);
	env = env_verif(*envlist, type);
	if (env)
	{
		free(type);
		free(env->info);
		env->info = info;
	}
	else
		ft_lstadd_front(envlist, ft_lstnew(new_env_list(type, info)));
}

t_env	*new_env_list(char *type, char *info)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (NULL);
	env->type = type;
	env->info = info;
	return (env);
}

t_env	*env_verif(t_list *env, char *type)
{
	t_list	*now;
	t_env	*envs;

	if (!env)
		return (NULL);
	now = env;
	while (now)
	{
		envs = (t_env *)now->content;
		if (!ft_strcmp(type, envs->type))
			return (envs);
		now = now->next;
	}
	return (NULL);
}
