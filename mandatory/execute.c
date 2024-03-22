/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:55:05 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/22 18:26:09 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	execute(t_a_s_tree *ast)
{
	int		status;
	pid_t	last;

	status = 0x7F;
	pipes_generate();
	last = execute_pipes(last);
	
}
