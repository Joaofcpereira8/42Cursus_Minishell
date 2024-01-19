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

/**
 * Main program.
 *
 * @param argc Necessita de apenas 1 arg;
 * @param argv Vai ser o minishell;
 * @param envp Variaveis de ambiente.
 *
 */

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

void	init(t_data *data)
{
	data->oldpwd = ft_get_env("OLDPWD");
	data->pwd = getcwd(0, 0);
	data->path_change = 0;
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	mini_init(env);


	char			*input;
	t_env_detail	envi;
	t_data			data;

	if	(argc > 1)
		return(err_handler('a', NULL));
	else
	{
		init(&data);
		ft_get_env1(&envi);
		while (1)
		{
			if (data.path_change == 1)
			{
				ft_get_env1(&envi);
				data.path_change = 0;
			}
			input = readline(envi.prompt);
			add_history(input);
			size_t len = strlen(input);
			if (len > 0 && input[len + 1] == '\n')
				input[len + 1] = '\0';
			char *args[] = {input, NULL};
			data.comm = args[0];
			if (built_type(&data, args) == -1)
				exec_command(&data, args, env);
			free(input);
		}
	}
}
