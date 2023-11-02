/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:16:15 by jofilipe          #+#    #+#             */
/*   Updated: 2022/11/22 13:44:21 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currentelement;

	currentelement = lst;
	if (currentelement == NULL)
		return (NULL);
	while (currentelement->next != NULL)
		currentelement = currentelement->next;
	return (currentelement);
}
