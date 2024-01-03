/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:42 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/03 14:43:31 by jofilipe         ###   ########.fr       */
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
}

void	init(t_data *data)
{
	data->oldpwd = getenv("OLDPWD");
	data->pwd = getcwd(0, 0);
	data->path_change = 0;
}

int main(int argc, char *argv[], char **env)
{
	//variavel da estrutura
	mini_init(env);

	(void)argv;
	char			*input;
	t_env_detail	envi;
	t_data			data;

	if (argc > 1)
		return(err_handler('a', NULL));
	else
	{
		init(&data);
		ft_get_env(&envi);
		while (1)
		{
			if (data.path_change == 1)
			{
				ft_get_env(&envi);
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
