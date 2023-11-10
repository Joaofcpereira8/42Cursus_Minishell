/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:24:15 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:11:46 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Apply a function to each character of a string, creating a new string
 * with the results.
 *
 * @param str String to iterate over.
 * @param f Pointer to the function to apply.
 *
 * @return Returns a new string containing the results of applying the
 *         function to each character, or NULL if memory allocation fails.
 */
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
