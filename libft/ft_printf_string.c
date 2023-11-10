/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:29:06 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:47 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print a string to the standard output.
 *
 * @param str String to be printed.
 *
 * @return Returns the number of characters printed.
 */
int	ft_printf_string(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		count += ft_printf_char(str[i]);
		i++;
	}
	return (count);
}
