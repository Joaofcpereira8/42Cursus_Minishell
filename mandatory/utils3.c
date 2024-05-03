/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:57:23 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/03 12:50:01 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	arr_size(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_skp(char *str, char *c)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(c, str[i]))
		i++;
	return (i);
}

int	ft_swap_env(char *swap, int i)
{
	swap = mini_shell()->senv[i];
	mini_shell()->senv[i] = mini_shell()->senv[i + 1];
	mini_shell()->senv[i + 1] = swap;
	return (0);
}

char	*ltm_join(t_env *env, char *tmp)
{
	char	*aux;
	char	*aux2;

	if (env->info[0] != '"')
	{
		aux = ft_strjoin(env->type, "=\"");
		aux2 = ft_strjoin(aux, env->info);
		tmp = ft_strjoin(aux2, "\"");
		free(aux2);
	}
	else
	{
		aux = ft_strjoin(env->type, "=");
		tmp = ft_strjoin(aux, env->info);
	}
	free(aux);
	return (tmp);
}

char	**lst_to_mat(t_list *list)
{
	t_env	*env;
	char	*tmp;
	char	**matrix;

	matrix = ft_calloc(1, sizeof(char *));
	if (!matrix)
		return (NULL);
	while (list)
	{
		env = (t_env *)list->content;
		if (env->info)
		{
			tmp = ltm_join(env, tmp);
			matrix = add_to_mat(matrix, ft_strdup(tmp));
			free(tmp);
		}
		else
			matrix = add_to_mat(matrix, ft_strdup(env->type));
		list = list->next;
	}
	return (matrix);
}
