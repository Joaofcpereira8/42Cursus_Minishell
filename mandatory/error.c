/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:02:29 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/15 18:29:26 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	err_handler(char c, char *cmd, int ext_sts)
{
	if (c == 'a')
		printf("Wrong number of arguments!\nUse ./minishell\n");
	else if (c == 's')
		printf("Unexpected error\n");
	else if (c == 'q')
		printf("minishell: Error: Unclosed quotes or special characters\n");
	else if (c == 'c')
		printf("%s: wrong arguments for command!"
			"\nTry 'man %s' for more information\n", cmd, cmd);
	else if (c == 'C')
		printf("%s: command not found\n", cmd);
	else if (c == 'd')
		printf("%s: no such file or directory\n", cmd);
	else if (c == 'h')
		printf("minishell: Error: Heredoc error\n");
	else if (c == 'e')
		printf("export: %s: Not a valid identifier\n", cmd);
	mini_shell()->exit_status = ext_sts;
	return (-1);
}

int	check_args(char **str)
{
	if (check_spec(str) == -1)
		return (err_handler('q', NULL, 0));
	return (0);
}

int	pars_error(char c, int ex_stat)
{
	if (c == 'q')
		printf("minishell: unclosed quotes\n");
	else if (c == 's')
		printf("minishell: syntax error near unexpected token\n");
	else if (c == 'r')
		printf("minishell: unclosed redirection\n");
	else if (c == 'p')
		printf("minishell: unclosed pipes\n");
	else if (c == 'b')
		printf("minishell: bad assignment\n");
	else if (c == 'z')
		printf("minishell: Error: No such file or directory\n");
	mini_shell()->exit_status = ex_stat;
	return (0);
}
