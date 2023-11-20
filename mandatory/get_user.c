/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/20 18:37:41 by jofilipe         ###   ########.fr       */
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

/*mudar o path tanto da estrutura como da funcao, pois o path vai ser sempre alterado e a funcao é static*/
int	ft_get_env(t_env_detail *envi)
{
	if (!envi)
	{
		// Invalid argument, return an error code
		return -1;
	}
	envi->user = getenv("USER");
	envi->sesh = getenv("SESSION_MANAGER");
	envi->path = getenv("PATH");
	return(0);
}

char	path_finder(t_data *data)
{
	data->cwd = get_path();
	return(0);
}
