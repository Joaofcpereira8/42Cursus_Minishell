/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:55 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print a long integer to the standard output.
 *
 * @param num Integer to be printed.
 *
 * @return Returns the number of characters printed.
 */
int	ft_printf_digit(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num *= -1;
		count += ft_printf_char('-');
	}
	if (num < 10)
		count += ft_printf_char(num + '0');
	else
	{
		count += ft_printf_digit(num / 10);
		count += ft_printf_digit(num % 10);
	}
	return (count);
}
