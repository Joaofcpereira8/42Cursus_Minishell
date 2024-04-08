/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:33:40 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/03 14:57:55 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	input(void)
{
	while (1)
	{
		mini_shell()->prompt = get_prompt();
		mini_shell()->input = readline(mini_shell()->prompt);
		if (!mini_shell()->input)
		{
			printf("exit\n");
			ft_free();
			ft_free_all();
		}
        if (mini_shell()->input[0])
		    add_history(mini_shell()->input);
		figure_out();
		// testing redirects:
		/* if (redirects(&data, args, red_out) == -1)
		{
			printf("Parser: Error in redirects\n");
			continue;
		} */
		env_update();
		ft_free();
	}
    rl_clear_history();
}
