/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:29:15 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:09:11 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Check and print the corresponding value based on the specifier
 * in the printf format.
 *
 * @param specifier Format specifier character.
 * @param var Variable argument list.
 *
 * @return Returns the number of characters printed.
 */
int	ft_checkprintf(char specifier, va_list var)
{
	int	bytes;

	bytes = 0;
	if (specifier == '%')
		bytes = ft_printf_char('%');
	else if (specifier == 'c')
		bytes = ft_printf_char(va_arg(var, int));
	else if (specifier == 's')
		bytes = ft_printf_string(va_arg(var, char *));
	else if (specifier == 'i' || specifier == 'd')
		bytes = ft_printf_digit(va_arg(var, int));
	else if (specifier == 'u')
		bytes = ft_printf_unsigned(va_arg(var, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		bytes = ft_printf_hexa(va_arg(var, unsigned int), specifier);
	else if (specifier == 'p')
		bytes = ft_printf_pointer(va_arg(var, unsigned long));
	return (bytes);
}

/**
 * Custom implementation of printf.
 *
 * @param str Format string.
 *
 * @return Returns the number of characters printed.
 */
int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	var;

	va_start(var, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_checkconversion(str[i + 1]))
			count += ft_checkprintf(str[i++ + 1], var);
		else if (str[i] == '%' && !ft_checkconversion(str[i + 1]))
		{
			count += write(1, "CONVERSION error", 17);
			return (count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(var);
	return (count);
}
