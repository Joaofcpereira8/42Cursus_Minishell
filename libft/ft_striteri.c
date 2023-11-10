/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:38:59 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:10:43 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Apply a function to each character of a string, passing its index
 * as the first argument.
 *
 * @param s String to iterate over.
 * @param f Pointer to the function to apply.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	upchar(unsigned int i, char *str)
{
	i = 0;
	while (str[i] >= 97 && str[i] <= 122)
		str[i] -= 32;
}
 */
