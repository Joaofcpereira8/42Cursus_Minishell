/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:50:48 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/25 12:54:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reallocates a memory block with a new size.
 *
 * This function reallocates the memory block pointed to by 'ptr'
 * to a new size specified by 'size'.
 * The contents of the original memory block are copied to the new memory block,
 * up to the minimum of the old and new sizes.
 * If the reallocation fails, NULL is returned and the original
 * memory block is left unchanged.
 * If the reallocation is successful, the original memory block is freed and a
 * pointer to the new memory block is returned.
 *
 * @param ptr   A pointer to the memory block to be reallocated.
 * @param size  The new size of the memory block, in bytes.
 * @return      A pointer to the reallocated memory block, or NULL if the
 *              reallocation fails.
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
