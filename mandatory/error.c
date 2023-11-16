/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:02:29 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/16 11:56:23 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int err_handler(char c)
{
	if (c == 'a')
		printf("Wrong number of arguments!\nUse ./minishell");
	else if (c == 's')
		printf("");
	else if (c == 'q')
		printf("Error: Unclosed quotes or special characters!");
	return (-1);
}
