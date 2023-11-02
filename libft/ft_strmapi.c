/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:24:15 by jofilipe          #+#    #+#             */
/*   Updated: 2022/11/29 16:58:27 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*memalloc;
	int		i;

	if (!str || !f)
		return (NULL);
	memalloc = malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (!memalloc)
		return (NULL);
	i = 0;
	while (str[i])
	{
		memalloc[i] = f(i, str[i]);
		i++;
	}
	memalloc[i] = '\0';
	return (memalloc);
}

/* static char	upchar(unsigned int i, char str)
{
	(void) i;

	while (str >= 97 && str <= 122)
		str -= 32;
	return (str);
}
 */
