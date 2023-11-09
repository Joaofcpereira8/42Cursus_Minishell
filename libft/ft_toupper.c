/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:38:24 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/09 18:16:26 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convert a lowercase letter to its corresponding uppercase letter.
 *
 * @param c Character to convert.
 *
 * @return Returns the uppercase equivalent of the character, if it is a lowercase letter;
 *         otherwise, returns the original character.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
