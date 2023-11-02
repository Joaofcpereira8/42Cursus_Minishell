/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:59 by jofilipe          #+#    #+#             */
/*   Updated: 2022/12/07 15:49:46 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
