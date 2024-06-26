/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islonglong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:58:46 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/03 12:29:05 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islonglong(char *c)
{
	while (*c)
	{
		if (!(((*c) >= '0') && ((*c) <= '9')))
			return (0);
		c++;
	}
	return (1);
}
