/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:38:01 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/25 14:24:20 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**tokenize(const char *str, const char *delimiters)
{
	int		start = 0;
	int		end = 0;
	int		tokenCount = 0;
	char	**tokens = NULL;
	char	*token = NULL;

	while (str[end] != '\0')
	{
		while (str[end] != '\0' && ft_strchr(delimiters, str[end]) == NULL)
			end++;
		token = malloc(end - start + 1);
		if (token == NULL)
			exit(-1); // memory allocation failed
		strncpy(token, &str[start], end - start);
		token[end - start] = '\0';
		tokens = ft_realloc(tokens, sizeof(char *) * (tokenCount + 1));
		if (tokens == NULL)
			exit(-1); // memory allocation failed
		tokens[tokenCount] = token;
		tokenCount++;
		while (str[end] != '\0' && ft_strchr(delimiters, str[end]) != NULL)
			end++;
		start = end;
	}
	tokens = ft_realloc(tokens, sizeof(char *) * (tokenCount + 1));
	tokens[tokenCount] = NULL;
	return (tokens);
}
