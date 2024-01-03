/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:02:29 by bbento-e          #+#    #+#             */
/*   Updated: 2023/12/05 18:45:14 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int err_handler(char c, char *cmd)
{
	if (c == 'a')
		printf("Wrong number of arguments!\nUse ./minishell\n");
	else if (c == 's')
		printf("Unexpected error\n");
	else if (c == 'q')
		printf("minishell: Error: Unclosed quotes or special characters!\n");
	else if (c == 'c')
		printf("minishell: Error: Wrong arguments for command!"
			   "\nTry 'man %s' for more information\n", cmd);
	else if (c == 'd')
		printf("minishell: Error: No such file or directory!\n");
	return (-1);
}

int check_args(char **str)
{
	if (check_spec(str) == -1)
		return (err_handler('q', NULL));
	return (0);
}