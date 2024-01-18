/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:38 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print an unsigned long integer in hexadecimal format to the standard output.
 *
 * @param hexa Unsigned long integer to be printed in hexadecimal.
 * @param c Character indicating whether to print in lowercase ('x')
 *          or uppercase ('X').
 *
 * @return Returns the number of characters printed.
 */
int	ft_printf_hexa(unsigned long hexa, char c)
{
	int		count;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (hexa < 16)
		count += ft_printf_char(base[hexa]);
	else
	{
		count += ft_printf_hexa(hexa / 16, c);
		count += ft_printf_hexa(hexa % 16, c);
	}
	return (count);
}
