/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:32:26 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/03 12:32:26 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*Concept called "singleton".
The mini_shell function returns a pointer to a static instance of t_mini_shell.
Static variables in C are allocated for the lifetime of the
program, not just the lifetime of the function call, so the t_mini_shell ms
instance will persist between calls to mini_shell().*/

t_mini_env	*mini_shell(void)
{
	static t_mini_env mini_shell;

	return (&mini_shell);
}
