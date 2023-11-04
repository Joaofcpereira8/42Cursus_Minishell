/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/04 19:40:06 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>

typedef struct s_data
{
	char	*env;
	char	*pid;
	char	*command;
}			t_data;

/*----exec.c----*/
int				ft_execvp();

/*----get_user.c----*/
static	void	ft_get_env(char **user, char **session);

// Checks
int				check_spec(char **str);

// Utils
int				iseven(int s_trig);

// Errors
int				err_handler(char c);

#endif
