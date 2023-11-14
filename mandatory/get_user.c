/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 16:56:41 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*vai buscar o user e o lugar onde se encontra nas
variaveis de ambiente*/
/*static*/	void	ft_get_env(t_env_detail env_det)
{
	env_det.user = getenv("USER");
	env_det.local = getenv("SESSION_MANAGER");
}
