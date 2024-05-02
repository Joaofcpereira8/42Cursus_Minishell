/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:57:23 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/02 15:07:12 by bbento-e         ###   ########.fr       */
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

void	env_join(char **arr1, char *str)
{
	int		size;
	int		i;
	char	**final;

	printf("Entering env_join with: %s\n", str);
	i = 0;
	size = arr_size(arr1) + 1;
	final = malloc(sizeof(char *) * size);
	while (i <= size && arr1[i])
	{
		final[i] = arr1[i];
		i++;
	}
	final[i] = str;
	//free_array(mini_shell()->senv);
	mini_shell()->senv = malloc(sizeof(char *) * size);
	mini_shell()->senv = final;
	printf("Joined env with str\n");
	// mini_shell()->tenv = envlist();
}

int	flag_setter(int	*flag)
{
	*flag = 1;
	return (1);
}

char    **lst_to_mat(t_list *list)
{
	t_env  *env;
	char   *tmp1;
	char   *tmp2;
	char   **matrix;

	matrix = ft_calloc(1, sizeof(char *));
	if (!matrix)
		return (NULL);
	while (list)
	{
		env = (t_env *)list->content;
		if (env->info) //== '"')
		{
			if (env->info[0] != '"')
			{
				tmp1 = ft_strjoin(env->type, "=\"");
				tmp2 = ft_strjoin(tmp1, ft_strjoin(env->info, "\""));
			}
			else
			{
				tmp1 = ft_strjoin(env->type, "=");
				tmp2 = ft_strjoin(tmp1, env->info);
			}
			matrix = add_to_mat(matrix, ft_strdup(tmp2));
			free(tmp1);
			free(tmp2);
		}
		else
		{
			tmp1 = ft_strdup(env->type);
			matrix = add_to_mat(matrix, ft_strdup(tmp1));
		}
		list = list->next;
	}
	return (matrix);
}
