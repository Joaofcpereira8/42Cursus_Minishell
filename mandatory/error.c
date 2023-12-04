/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:02:29 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/29 18:55:13 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int err_handler(char c, char *cmd)
{
	if (c == 'a')
		printf("Wrong number of arguments!\nUse ./minishell");
	else if (c == 's')
		printf("Unexpected error");
	else if (c == 'q')
		printf("minishell: Error: Unclosed quotes or special characters!\n");
	else if (c == 'c')
		printf("minishell: Error: Too many arguments for command!"
			   "\nTry 'man %s' for more information\n", cmd);
	else if (c == 'd')
		printf("minishell: Error: No such file or directory!\n 9l 5");
	return (-1);
}
