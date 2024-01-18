/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:48:06 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:04:57 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculate the absolute value of a number.
 *
 * @param nbr Number to find the absolute value of.
 *
 * @return Returns the absolute value of the input number.
 */
static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

/**
 * Count the number of digits in an integer.
 *
 * @param nbr Integer to count digits of.
 *
 * @return Returns the count of digits in the input integer.
 */
static int	ft_digit_count(int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

/**
 * Convert an integer to a string.
 *
 * @param n Integer to be converted.
 *
 * @return Returns the string representation of the input integer.
 *         Returns NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_digit_count(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = 48;
	while (n != 0)
	{
		str[i--] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
