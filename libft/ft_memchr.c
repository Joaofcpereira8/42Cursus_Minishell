/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:31:46 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:07:09 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locate the first occurrence of a byte in a block of memory.
 *
 * @param str Pointer to the block of memory.
 * @param c Byte to be located.
 * @param n Number of bytes to search.
 *
 * @return Returns a pointer to the first occurrence of the byte in the
 *         block of memory.
 *         Returns NULL if the byte is not found within the specified
 *         number of bytes.
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
