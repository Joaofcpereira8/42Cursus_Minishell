/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:29:01 by jofilipe          #+#    #+#             */
/*   Updated: 2022/12/07 15:51:17 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
