/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:33:40 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/29 11:53:27 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	init(t_data *data)
{
	data->oldpwd = getenv("OLDPWD");
	data->pwd = getcwd(0, 0);
	//data->path_change = 0;
}

void	parser(void)
{
	char	*input;
	t_data	data;

	init(&data);
	while (1)
	{
		get_prompt(mini_shell());
		input = readline(mini_shell()->prompt);
		//se nao houver prompt(ctrl + d, etc) clear history e dar free a tudo
		add_history(input);
		size_t len = strlen(input);
		if (len > 0 && input[len + 1] == '\n')
			input[len + 1] = '\0';
		char *args[] = {input, NULL};
		data.comm = args[0];
		if (built_type(&data, args) == -1)
			exec_command(&data, args, mini_shell());
		free(input);
	}
}