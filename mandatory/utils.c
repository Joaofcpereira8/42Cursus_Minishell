/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:02 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/29 18:54:40 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_strlen_flag(char const *str, char flag)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != flag)
		i++;
	return(i);
}