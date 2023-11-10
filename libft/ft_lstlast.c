/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:16:15 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:05:44 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Get the last element of a linked list.
 *
 * @param lst The first element of the list.
 *
 * @return Returns a pointer to the last element of the list.
 *         Returns NULL if the list is empty.
 */
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
