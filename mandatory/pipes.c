/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:50:32 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/22 18:24:31 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	pipes_generate(void)
{
	int	i;

	mini_shell()->pipes = ft_calloc(mini_shell()->cmd_num, sizeof(int));
	if (!mini_shell()->pipes)
		return ;
	i = 0;
	while (i++ < mini_shell()->cmd_num - 1)
	{
		(mini_shell()->pipes[i] = ft_calloc(2, sizeof(int)));
		pipe(mini_shell()->pipes[i]);
	}
}

pid_t	execute_pipes(t_a_s_tree *node)
{
	pid_t	last;

	last = 0;
	if (!node)
		return (node);
	last = execute_pipes(node->left);
	last = execute_pipes(node->right);
	if (!pipe_or_redir(node->token))
	{

	}

}

/* void	pipes(void)
{
	(mini_shell()->fd_in) = open(mini_shell()->input, O_RDONLY, 0444);
	if (errno)
	{
		printf("%s: %s\n", strerror(errno));
		return (-1);
	}
	(mini_shell()->fd_out) = open(mini_shell()->input, O_CREAT | O_RDONLY | O_TRUNC, 0664);
	if (errno)
	{
		printf("%s: %s\n", strerror(errno));
		return (-1);
	}

} */
