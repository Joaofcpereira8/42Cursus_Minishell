/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:50:32 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/11 10:14:55 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	pipes_generate(void)
{
	int	i;

	mini_shell()->pipes = ft_calloc(mini_shell()->cmd_num, sizeof(int *));
	if (!mini_shell()->pipes)
		return ;
	i = -1;
	while (++i < mini_shell()->cmd_num - 1)
	{
		(mini_shell()->pipes[i]) = ft_calloc(2, sizeof(int));
		pipe(mini_shell()->pipes[i]);
	}
}

pid_t	execute_pipes(t_a_s_tree *node)
{
	pid_t	last;

	last = 0;
	if (!node)
		return (last);
	last = execute_pipes(node->left);
	last = execute_pipes(node->right);
	if (!pipe_or_redir(node->token))
	{
		if(is_built_in(node->args[0], node->args[1]))
			built_type(node->args);
		else
			last = exec_is_fork(node);
	}
	else if (redirection(node->token))
		redirects(node->token->type, node->args[0]);
	return (last);
}

void	atribute_pipes_fd(int index_command)
{
	if (mini_shell()->cmd_num < 2)
		return ;
	if (mini_shell()->fd_in == STDIN_FILENO)
		if (index_command != 0)//ler no fim -> 0
			mini_shell()->fd_in = mini_shell()->pipes[index_command - 1][READ_PI];
	if (mini_shell()->fd_out == STDOUT_FILENO)//escrever no fim -> 1
		if (!is_last_command(index_command))
			mini_shell()->fd_out = mini_shell()->pipes[index_command][WRITE_PI];
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
