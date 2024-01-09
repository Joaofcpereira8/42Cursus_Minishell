/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:02 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/29 18:54:40 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_strlen_flag(char const *str, char flag)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != flag)
		i++;
	return(i);
}

int	sz_env_list(char **env)
{
    int	i;

    if(!env)
        return(-1);
    i = 0;
    while(env[i])
        i++;
    return(i);
}

void    list_delete(void *list)
{
    int i;
    char **prov_lst;

    if (!list)
        return ;
    i = 0;
    prov_lst = (char **)list;
    while(prov_lst[i])
        free(prov_lst[i++]);//
    free(list);
}

char    **add_to_mat(char **mat1, char *str)
{
    char    **mat2;
    int     i;

    i = -1;
    mat2 = ft_calloc(sz_env_list(mat1) + 2, sizeof(char *));
    //The +2 is for the new string and the NULL terminator at the end of the matrix.
    if(!mat2)
        return (NULL);
    while(mat1[++i])
        mat2[i] = ft_strdup(mat1[i]);
    mat2[i] = str;
    list_delete(mat1);
    return(mat2);
}