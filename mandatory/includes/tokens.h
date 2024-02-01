/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:49:39 by jofilipe          #+#    #+#             */
/*   Updated: 2024/02/01 12:04:43 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"

typedef enum e_meta_tok
{
	red_in,
	red_apnd,
	red_out,
	red_hdoc,
	piped,
	sng_quote,
	dbl_quote,
}			t_meta_tok;

typedef struct s_token
{
	char		*str;
	t_meta_tok	type;
}				t_token;

t_token	*new_token(char *str, t_meta_tok type);
int		conv_to_token(char *str, t_meta_tok type);

#endif