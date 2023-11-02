/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:51 by jofilipe          #+#    #+#             */
/*   Updated: 2022/11/29 16:55:16 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
