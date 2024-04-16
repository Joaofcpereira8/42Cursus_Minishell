/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:33:40 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/28 17:53:35 by jofilipe         ###   ########.fr       */
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
		if (!*mini_shell()->input)
			continue ;
		add_history(mini_shell()->input);
		figure_out();
		ft_free();
	}
	rl_clear_history();
}
