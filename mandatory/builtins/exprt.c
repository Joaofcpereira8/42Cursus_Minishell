/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:13:24 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/10 15:51:39 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list *miniexport(void)
{
	int		i;
	int		size;
	t_list 	*temp;
	char	*swap;

	printf("Entered miniexport\n");
	printexp();
	i = 0;
	size = lst_size(mini_shell()->env_amb_list);
	temp = mini_shell()->env_amb_list;
	while (i < (size - 1))
	{
		i = 0;
		if (((char*)temp->content)[i] == ((char*)temp->next->content)[i])
		{
			while ((((char*)temp->content)[i] || ((char*)temp->next->content)[i])
				   && (((char*)temp->content)[i] == ((char*)temp->next->content)[i]))
				i++;
		}
		if (((char*)temp->content)[i] > ((char*)temp->next->content)[i])
		{
			swap = temp->content;
			temp->content = temp->next->content;
			temp->next->content = swap;
			temp = mini_shell()->env_amb_list;
			i = 0;
		}
		temp = temp->next;
		i++;
	}
	return (temp);
}

void	printexp(void)
{
	t_list	*current;

	printf("Started printing export\n");
	current = mini_shell()->env_amb_list;
	while (current != NULL)
	{
		printf("%s\n", (char*)(current->content));
		current = current->next;
	}
}
