/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:42 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/09 18:40:08 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

/**
 * Main program.
 *
 * @param argc Necessita de apenas 1 arg;
 * @param argv Vai ser o minishell;
 * @param envp Variaveis de ambiente.
 *
 */

int main(int argc, char *argv[], char **env)
{
	(void)argv;

	if (argc > 1)
		return(ft_putstr_fd("Too much arguments! Use only ./minishell\n", 2), 1);
	else
	{
		/*inits*/
		while (1)
		{
			/* code */
		}

	}

}
