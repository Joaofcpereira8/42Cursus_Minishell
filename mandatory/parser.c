/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:33:40 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/19 14:06:37 by bbento-e         ###   ########.fr       */
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
	t_data	data;

	init(&data);
	while (1)
	{
		get_prompt(mini_shell());
		mini_shell()->input = readline(mini_shell()->prompt);
		if (!mini_shell()->input)
		{
            printf("exit\n");
			// se nao houver prompt(ctrl + d, etc)
			// clear history e dar free a tudo
		}
		add_history(mini_shell()->input);
		figure_out();
		char *args[] = {mini_shell()->input, NULL};
		data.comm = args[0];
		if (built_type(&data, args) == -1)
			exec_command(&data, args, mini_shell());
		// Testing redirects
		if (redirects(&data, args, red_out) == -1)
		{
			printf("Parser: Error in redirects\n");
			continue;
		}
		// free(mini_shell()->input);
	}
}
