/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:29:11 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:53 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print an unsigned integer to the standard output.
 *
 * @param num Unsigned integer to be printed.
 *
 * @return Returns the number of characters printed.
 */
int	ft_printf_unsigned(unsigned int num)
{
	int	count;

	count = 0;
	if (num < 10)
	{
		count += ft_printf_char(num + '0');
	}
	else
	{
		count += ft_printf_digit(num / 10);
		count += ft_printf_digit(num % 10);
	}
	return (count);
}
