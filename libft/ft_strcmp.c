/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:10:44 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/04 12:10:46 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(const char *s1, const char *s2)
{
    int i;
    i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return(s1[i] - s2[i]);
}