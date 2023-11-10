/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:44:56 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:07 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Set a block of memory to a specified value.
 *
 * @param str Pointer to the block of memory.
 * @param c Value to set each byte to.
 * @param len Number of bytes to set.
 *
 * @return Returns a pointer to the block of memory.
 */
void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}
