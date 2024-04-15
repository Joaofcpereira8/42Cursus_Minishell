/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:51:41 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:02:55 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_see_spaces - Function to skip leading whitespaces and identify sign.
 *
 * @param str Input string.
 * @param ptr_i Pointer to the index where parsing should start.
 *
 * @return Returns the sign of the numeric value (1 or -1).
 */
static int	ft_see_spaces(const char *str, int *ptr_i)
{
	int	negative;
	int	i;

	i = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	*ptr_i = i;
	return (negative);
}

/**
 * ft_atoi - Convert ASCII string to integer.
 *
 * @param str Input string to be converted.
 *
 * @return Returns the converted integer value.
 */
int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		negative;

	i = 0;
	result = 0;
	negative = ft_see_spaces(str, &i);
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0')
	{
		result *= negative;
		return (result);
	}
	return (-1);
}
