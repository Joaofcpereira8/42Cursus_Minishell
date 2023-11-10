/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:34 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:06:10 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Create a new list resulting from the application of a function to each
 * element's content.
 *
 * @param lst The first element of the original list.
 * @param f The function to apply to each element's content.
 * @param del The deletion function to free the memory of any newly allocated
 *            element in case of failure.
 *
 * @return Returns a pointer to the new list.
 *         Returns NULL if any of the input parameters are invalid or if memory
 *         allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	head = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew((*f)(lst->content)));
		lst = lst->next;
	}
	return (head);
}
