/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:40:49 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:13:56 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convert an uppercase letter to its corresponding lowercase letter.
 *
 * @param c Character to convert.
 *
 * @return Returns the lowercase equivalent of the character, if it is an
 *         uppercase letter;
 *         otherwise, returns the original character.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
