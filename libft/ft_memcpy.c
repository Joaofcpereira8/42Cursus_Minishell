/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:04:58 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:07:53 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy a block of memory from source to destination.
 *
 * @param dest Pointer to the destination block of memory.
 * @param src Pointer to the source block of memory.
 * @param len Number of bytes to copy.
 *
 * @return Returns a pointer to the destination block of memory.
 */
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
