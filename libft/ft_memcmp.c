/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:45:34 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:07:46 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compare two blocks of memory.
 *
 * @param str1 Pointer to the first block of memory.
 * @param str2 Pointer to the second block of memory.
 * @param n Number of bytes to compare.
 *
 * @return Returns an integer less than, equal to, or greater than zero
 *         if the first n bytes of str1 are found, respectively, to be
 *         less than, to match, or be greater than the first n bytes of str2.
 */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	if (n <= 0)
		return (0);
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n > i)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
