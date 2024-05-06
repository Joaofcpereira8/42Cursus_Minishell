/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:33:40 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/03 17:53:08 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	input(void)
{
	while (1)
	{
		(mini_shell()->prompt) = get_prompt();
		(mini_shell()->input) = readline(mini_shell()->prompt);
		free(mini_shell()->prompt);
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
		printf("Exit status is -> %i\n", mini_shell()->exit_status);
		ft_free();
	}
}
