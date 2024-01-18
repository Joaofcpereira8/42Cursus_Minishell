/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:29:01 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:49 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print a pointer address in hexadecimal format to the standard output.
 *
 * @param num Pointer address to be printed.
 *
 * @return Returns the number of characters printed.
 */
int	ft_printf_pointer(unsigned long num)
{
	int	count;

	count = 0;
	if (!num)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	count += ft_printf_hexa(num, 'x');
	return (count + 2);
}
