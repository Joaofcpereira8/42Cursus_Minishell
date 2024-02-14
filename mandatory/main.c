/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:42 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/10 10:10:55 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	mini_init(char	**env)
{
	ft_bzero(mini_shell(), sizeof(t_mini_env));
	(mini_shell()->env_amb_list) = envlist(env);
	env_update();
	(mini_shell()->exit_status) = 0;
	(mini_shell()->cwd) = getcwd(0, 0);
	(mini_shell()->fd_in) = STDIN_FILENO;
	(mini_shell()->fd_out) = STDOUT_FILENO;
	return ;
}

/**
 * Main program.
 *
 * @param argc Necessita de apenas 1 arg;
 * @param argv Vai ser o minishell;
 * @param envp Variaveis de ambiente.
 *
 */
int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	mini_init(env);
    parser();
}
