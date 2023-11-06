/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/06 12:41:37 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	ft_get_env(char **user, char **session)
{
	user = getenv("USER");
	session = getenv("SESSION_MANAGER");
}
