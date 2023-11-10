/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:51 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:04:27 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocate and zero-initialize a block of memory.
 *
 * @param nmemb Number of elements.
 * @param size Size of each element.
 *
 * @return Returns a pointer to the allocated memory block.
 *         Returns NULL if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		area;
	int		i;

	area = nmemb * size;
	ptr = malloc(area);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (area))
		*(ptr + i++) = '\0';
	return ((void *)ptr);
}
