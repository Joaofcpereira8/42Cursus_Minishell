/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:57 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/29 12:11:36 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minienv(t_list *env_amb_list)
{
	int	i;

	(void)env_amb_list;
	i = 0;
	while (mini_shell()->env[i])
	{
		printf("%s\n", mini_shell()->env[i]);
		i++;
	}
}

void	env_update(void)
{
	char	*tmp;

	list_delete(mini_shell()->path);
	list_delete(mini_shell()->env);
	tmp = ft_get_env("PATH");
	mini_shell()->path = ft_split(tmp, ':');
	mini_shell()->env = env_to_mat(mini_shell()->env_amb_list);
	free(tmp);
}

char	**env_to_mat(t_list *env_list)
{
	t_env	*env;
	char	*tmp1;
	char	*tmp2;
	char	**matrix;

	matrix = ft_calloc(1, sizeof(char *));
	if (!matrix)
		return (NULL);
	while (env_list)
	{
		env = (t_env *)env_list->content;
		if (env->info && env->info[1] && env->info[1] != '"')
		{
			tmp1 = ft_strjoin(env->type, "=");
			if (env->info[0] == '"')
				tmp2 = ft_strjoin(tmp1, ft_strtrim(env->info, "\""));
			else
				tmp2 = ft_strjoin(tmp1, env->info);
			matrix = add_to_mat(matrix, ft_strdup(tmp2));
			free(tmp1);
			free(tmp2);
		}
		env_list = env_list->next;
	}
	return (matrix);
}

char	*ft_get_env(char *type)
{
	t_env	*env_tmp;
	t_list	*current;

	if (type[0] == '$')
		type++;
	current = mini_shell()->env_amb_list;
	while (current)
	{
		env_tmp = (t_env *)current->content;
		if (!ft_strcmp(env_tmp->type, type))
			return (ft_strdup(env_tmp->info));
		current = current->next;
	}
	return (ft_strdup(""));
}
