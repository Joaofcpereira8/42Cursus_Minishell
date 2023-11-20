/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/20 18:34:22 by jofilipe         ###   ########.fr       */
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
# include <readline/history.h>


# define MAX_INPUT_SIZE 1024

typedef enum e_type
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
}				t_type;

typedef struct s_env_detail
{
	char	*user;
	char	*sesh;
	char	*path;
}				t_env_detail;

typedef struct s_token
{
	char	*str;
	t_type	type;
}				t_token;

typedef struct s_data
{
	char		**env;
	int			pid;
	char		*command;
	char		*cwd;
}				t_data;

/*----exec.c----*/
int				ft_execvp();

/*----get_user.c----*/
int				ft_get_env(t_env_detail *envi);
char			*get_path(void);
char			path_finder(t_data *data);

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
