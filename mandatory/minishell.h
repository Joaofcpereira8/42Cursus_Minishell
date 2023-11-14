/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 16:52:53 by jofilipe         ###   ########.fr       */
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

# define MAX_TOKEN_SIZE
# define MAX_INPUT_SIZE 1024

typedef enum e_tok_type
{
	KEYWORD,
	IDENTIFIERS,
	OPERATORS,
	LITERALS,
	PUNCTUATION,
	COMMENTS,
	SPECIAL_SYMBOLS,
	WHITESPACE,
	EOF_TOKE,
}				t_tok_type;

typedef struct s_env_detail
{
    char    *user;
    char    *local;
}               t_env_detail;

typedef struct s_token
{
	t_tok_type 	type;
	char		value[MAX_TOKEN_SIZE];
}				t_token;

typedef struct s_data
{
	char		**env;
	int			pid;
	char		*command;
}				t_data;

/*----exec.c----*/
int				ft_execvp();

/*----get_user.c----*/
/*static*/	void	ft_get_env(t_env_detail env_det);

/*----parser.c----*/
void			exec_command(char **argv, char **env);

/*----readline.c.c----*/


/*----special.c----*/
int				check_spec(char **str);
int				iseven(int s_trig);

/*----error.c----*/
int				err_handler(char c);

/*----utils.c----*/
int				check_args(char **str);

#endif
