/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2023/12/07 16:00:52 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"
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
	char	*path_env;
	char	*prompt;
}				t_env_detail;

typedef struct s_token
{
	char	*str;
	t_type	type;
}				t_token;

typedef struct s_data
{
	char 		*oldpwd;
	char		*pwd;
	int			pid;
	char		*comm;
	char		*cwd;
	char 		**paths;
	int 		path_change;
}				t_data;

//working on the real deal.
typedef struct s_mini_env
{
	int		fd_in;
	int		fd_out;
	int		exit_status;
	int		command_num;
	char	*cwd;
	char	*input;
};

// ------ EXECVE ------
void	get_paths(t_data *data);
char	*path_join(char *path, char *cm);
void	exec_command(t_data *data, char **args, char **env);

// ------ USER ------
char	pwd_finder(t_data *data);
void	ft_get_env(t_env_detail *envi);

// ----- BUILT-INs -----
int		minipdw(t_data *data);
int		minicd(t_data *data, char **args);
int		minienv(t_data *data, char **args);
int		miniecho(t_data *data, char **args);
void	miniexit(t_data *data, char **args);
int		miniunset(t_data *data, char **args);
int		miniexport(t_data *data, char **args);
int		built_type(t_data *data, char **args);
int		built_type_next(t_data *data, char **args);


// ----- PARSER -----
int		iseven(int s_trig);
int		check_spec(char **str);

// ------ ERRORS -----
int err_handler(char c, char *cmd);

// ----- UTILS -----
int		check_args(char **str);

#endif
