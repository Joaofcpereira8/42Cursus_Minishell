/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:37:14 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/02 12:00:55 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

bool	builtin_verif(char *command)
{
	return((!ft_strcmp(command, "echo")) || (!ft_strcmp(command, "cd"))
			|| (!ft_strcmp(command, "pwd")) || (!ft_strcmp(command, "export"))
			|| (!ft_strcmp(command, "unset")) || (!ft_strcmp(command, "env"))
			|| (!ft_strcmp(command, "exit")));
}
