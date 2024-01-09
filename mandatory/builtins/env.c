/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:57 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/29 12:11:59 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void    env_update(void)
{
    char *tmp;

    list_delete(mini_shell()->path);
    list_delete(mini_shell()->env);
    tmp = getenv("PATH");
    mini_shell()->path = ft_split(tmp, ':');
    mini_shell()->env = env_to_mat(mini_shell()->env_amb_list);
    free(tmp);
}

char **env_to_mat(t_list *env_list)
{
    t_env   *env;
    char    *tmp1;
    char    *tmp2;
    char    **matrix;

    matrix = ft_calloc(1, sizeof(char *));
    if(!matrix)
        return(NULL);
    while(env_list)
    {
        env = (t_env *)env_list->content;
        tmp1 = ft_strjoin(env->type, "=");
        tmp2 = ft_strjoin(tmp1, env->info);
        matrix = add_to_mat(matrix, ft_strdup(tmp2));
        free(tmp1);
        free(tmp2);
        env_list = env_list->next;
    }
    return (matrix);
}