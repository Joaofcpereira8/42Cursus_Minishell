/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/19 16:38:54 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"
# include "env.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# define SYM	"<>\'\"| "
# define QUO	"\'\""
# define SPE	"<>| "

typedef struct s_data
{
	int			fd;
	char		*oldpwd;
	char		*pwd;
	int			path_change;
	int			pid;
	char		*comm;
	char		**paths;
}				t_data;

//working on the real deal.
//experimentar input como char **
//e quando encontra um | ou >>
//incrementa para o proximo array

/**
 *@brief "Global" variable that's used in the majority
 *of the project
 *
 *@param fd_in Standard input fd
 *@param fd_out Standard output fd
 *@param exit_status Last command's exit status
 *@param cmd_num Number of commands
 *@param cwd Current working directory
 *@param input Input in the command line
 *@param prompt Prompt in the command line
 *@param env Environment ambient's matrix
 *@param path Environment ambient's PATH
 *@param env_amb_list Linked list of the environment variables
 *@param env_token Linked list of metacharacters tokens
 *
 *
*/
typedef struct s_mini_env
{
	int		fd_in;
	int		fd_out;
	int		exit_status;
	int		cmd_num;
	char	*cwd;
	char	*input;
	char	*prompt;
	char	**env;
	char	**path;
	t_list	*env_amb_list;
	t_list	*env_token;
}			t_mini_env;

typedef enum e_meta_tok
{
	red_in,
	red_apnd,
	red_out,
	red_hdoc,
	piped,
	sng_quote,
	dbl_quote,
	rest,
}			t_meta_tok;

typedef struct s_token
{
	char		*str;
	t_meta_tok	type;
	bool		can_join;
}				t_token;

typedef enum e_operations
{
	READ,
	NEXT,
	AFTER,
	RESET
}			t_operations;

//typedef enum e_meta_tok t_meta_tok;

// ------ EXECVE ------ //
void		get_paths(t_data *data);
char		*path_join(char *path, char *cm);
void		exec_command(t_data *data, char **args, t_mini_env *envp);

// ------ USER ------ //
char		pwd_finder(t_data *data);
void		get_prompt(t_mini_env *envp);

// ----- BUILT-INs ----- //
int			minipdw(t_data *data);
void		minienv(t_list *env_amb_list);
int			minicd(t_data *data, char **args);
int			miniecho(t_data *data, char **args);
void		miniexit(t_data *data, char **args);
int			miniunset(t_data *data, char **args);
int			miniexport(t_data *data, char **args);
int			built_type(t_data *data, char **args);
int			built_type_next(t_data *data, char **args);

// ----- PARSER ----- //
void		parser(void);
int			iseven(int s_trig);
int			check_spec(char **str);

// ----- REDIRECTS ---- //
int			heredoc(char *file);
int			handle_hdoc(t_data *data, char **comm);
int			handle_appnd(t_data *data, char **comm);
int			handle_input(t_data *data, char **comm);
int			handle_output(t_data *data, char **comm);
int			redirects(t_data *data, char **comm, t_meta_tok token);

// ------ ERRORS ----- //
int			err_handler(char c, char *cmd);
int			check_args(char **str);

// ----- UTILS ----- //
int			sz_env_list(char **env);
void		list_delete(void *list);
int			is_every_space(char *str);
int			pars_error(char c, int ex_stat);
int			ft_strlen_skp(char *str, char *c);
char		**add_to_mat(char **mat1, char *str);
int			ft_strlen_flag(char const *str, char flag);

// ---- VARIABLE_GLOBAL ---- //
t_mini_env	*mini_shell(void);

// ---- ENV ---- //
void		env_update(void);
char		*ft_get_env(char *type);
char		**env_to_mat(t_list *env_list);

// ---- ENV_VAR_LIST ---- //
t_list		*envlist(char **env);
t_env		*env_verif(t_list *env, char *type);
t_env		*new_env_list(char *type, char *info);
void		add_env_vars(t_list **envlist, char *container);

// ---- INPUT_VERIF ---- //
int			figure_out(void);
bool		metacharacters_verif(void);
int			find_sym(char *quote, char *str);
bool		is_joinable(char *str, char *match, int skip);
void		read_metachar(void);

// ---- INPUT_VERIF2 ---- //
bool		input_analysis(void);
t_token		*scanner(t_operations operations);
bool		pipe_or_redir(t_token *token);
bool		redirection(t_token *token);

// ---- EXPANDER ---- //
void		expander(void);
void		expand_variable(t_token *token);
char		*find_key(char *str);
char		*ft_streplace(char *str, char *old, char *new);

// ---- FREE ---- //
void		ft_clean(void *pointer);


/**
 * @brief Checks for the balanced use of quotes in a given input string.
 *
 * This function ensures that quotes (single or double) in
 * the input string are properly balanced, i.e., every opening
 * quote has a corresponding closing quote. It also handles the case of unclosed quotes.
 *
 * @return Returns true if quotes are balanced; otherwise,
 * returns false and sets the exit status for an unclosed quote.
 */
bool		metacharacters_verif(void);

/** @brief Reads metacharacters from the shell's input string and converts them into tokens.
 *
 * This function iterates through the shell's input string and identifies metacharacters,
 * including pipes (|), redirection symbols (<, >, >>, <<), and quotes (single and double).
 * It converts these metacharacters into tokens, which represent commands, arguments,
 * and special constructs in the shell's language.
 *
 * @return None
 */
void		read_metachar(void);

// ---- TOKENS ----
int     find_sym(char *quote, char *str);
bool    is_joinable(char *str, char *match, int skip);
t_token *new_token(char *str, t_meta_tok type, bool join);
int     conv_to_token(char *str, t_meta_tok type, bool joinable);


#endif
