/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/16 18:30:45 by bbento-e         ###   ########.fr       */
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
/*static*/	void	ft_get_env(t_env_detail *envi)
{
/*	env_det = getenv("USER");
	session = getenv("SESSION_MANAGER");*/
	envi->user = getenv("USER");
	envi->sesh = getenv("SESSION_MANAGER");
	envi->path = get_path();


}