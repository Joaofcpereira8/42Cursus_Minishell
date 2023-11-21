/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/21 19:15:19 by bbento-e         ###   ########.fr       */
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
	char		*comm;
	char		*cwd;
}				t_data;

// ------ EXEC ------
int				ft_execvp();

// ------ USER ------
char	*get_path(void);
char	path_finder(t_data *data);
int		ft_get_env(t_env_detail *envi);

// ----- BUILT-INs -----
int		minicd(t_data *data, char **args);
int		minipdw(t_data *data, char **args);
int		minienv(t_data *data, char **args);
int		miniexit(t_data *data, char **args);
int		miniecho(t_data *data, char **args);
int		miniunset(t_data *data, char **args);
int		miniexport(t_data *data, char **args);
int		built_type(t_data *data, char **args);
int		builttype_next(t_data *data, char **args);


// ----- PARSER -----
void	exec_command(char **argv, char **env);

/*----readline.c.c----*/


/*----special.c----*/
int		iseven(int s_trig);
int		check_spec(char **str);

// ------ ERRORS -----
int		err_handler(char c);

// ----- UTILS -----
int				check_args(char **str);

#endif
