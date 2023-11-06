/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:42 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/06 12:42:11 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_args(char **str)
{
	if (check_spec(str) == -1)
		return (err_handler('q'));
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		if (check_args(argv) != -1)
		{
			/* code */
		}
	}
	else
		return (0);
}
