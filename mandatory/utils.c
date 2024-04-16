/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:02 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/16 15:57:41 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_strlen_flag(char const *str, char flag)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != flag)
		i++;
	return (i);
}

int	sz_env_list(char **env)
{
	int	i;

	if (!env)
		return (-1);
	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	list_delete(void *list)
{
	int		i;
	char	**prov_lst;

	if (!list)
		return ;
	i = 0;
	prov_lst = (char **)list;
	while (prov_lst[i])
		ft_clean(prov_lst[i++]);
	ft_clean(list);
}

char	**add_to_mat(char **mat1, char *str)
{
	char	**mat2;
	int		i;

	i = -1;
	mat2 = ft_calloc(sz_env_list(mat1) + 2, sizeof(char *));
	if (!mat2)
		return (NULL);
	while (mat1[++i])
		mat2[i] = ft_strdup(mat1[i]);
	mat2[i] = str;
	list_delete(mat1);
	return (mat2);
}

int	is_every_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\b' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r'
			&& str[i] != ' ')
			return (0);
		i++;
	}
	return (-1);
}
