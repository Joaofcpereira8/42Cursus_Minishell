/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:46 by jofilipe          #+#    #+#             */
/*   Updated: 2022/11/29 16:57:14 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*memalloc;
	int		i;

	i = 0;
	memalloc = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (memalloc == NULL)
		return (NULL);
	while (str[i])
	{
		memalloc[i] = str[i];
		i++;
	}
	memalloc[i] = '\0';
	return (memalloc);
}
