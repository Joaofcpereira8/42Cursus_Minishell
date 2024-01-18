/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:11:23 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:12:17 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compare two strings up to a specified number of characters.
 *
 * @param str1 First string to compare.
 * @param str2 Second string to compare.
 * @param n Number of characters to compare.
 *
 * @return Returns an integer less than, equal to, or greater than zero if the
 * first n characters of str1 are found, respectively, to be less than,
 * to match, or be greater than the first n characters of str2.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
