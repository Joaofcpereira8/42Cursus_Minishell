/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:42 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/03 11:42:33 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	mini_init(char	**env)
{
	ft_bzero(mini_shell(), sizeof(t_mini_env));
	(mini_shell()->env_amb_list) = envlist(env);
	env_update();
	(mini_shell()->exit_status) = 0;
	(mini_shell()->cwd) = getcwd(0, 4096);
	(mini_shell()->oldpwd) = ft_get_env("OLDPWD");
	(mini_shell()->fd_in) = STDIN_FILENO;
	(mini_shell()->fd_out) = STDOUT_FILENO;
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	mini_init(env);
	signals();
	input();
	return (0);
}
