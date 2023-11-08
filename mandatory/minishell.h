/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:44 by jofilipe         ###   ########.fr       */
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
	char	**env;
	int		pid;
	char	*command;
}			t_data;

/*----exec.c----*/
int				ft_execvp();

/*----get_user.c----*/
static	void	ft_get_env(char **user, char **session);

/*----parser.c----*/


/*----readline.c.c----*/


/*----special.c----*/
int				check_spec(char **str);
int				iseven(int s_trig);

/*----error.c----*/
int				err_handler(char c);

/*----utils.c----*/
int				check_args(char **str);

#endif
