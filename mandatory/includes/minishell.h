/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/07 17:45:51 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <errno.h>
# include <sys/types.h>

# define SYM		"<>\'\"| "
# define QUO		"\'\""
# define SPE		"<>| "
# define RE_PI	0
# define WR_PI	1

typedef enum e_meta_tok
{
	red_in,
	red_out,
	red_apnd,
	red_hdoc,
	piped,
	sng_quote,
	dbl_quote,
	rest,
}			t_meta_tok;

typedef enum e_operations
{
	READ,
	NEXT,
	AFTER,
	RESET
}			t_operations;

typedef struct s_env
{
	char			*type;
	char			*info;
}				t_env;

typedef struct s_token
{
	char		*str;
	t_meta_tok	type;
	bool		can_join;
}				t_token;

/**
 * @brief A structure to represent a node of an Abstract Syntax Tree
 *
 *@param token The token associated with the node
 *@param args The arguments of the token
 *@param index Used if the token represents a command
 *@param left The left child of the node
 *@param right The right child of the node
 */
typedef struct s_a_s_tree
{
	t_token				*token;
	char				**args;
	int					index;
	struct s_a_s_tree	*right;
	struct s_a_s_tree	*left;
}			t_a_s_tree;

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
 *@param senv Environment ambient's matrix for export
 *@param path Environment ambient's PATH
 *@param pipes Pipes and it's respective fd
 *@param oldpwd Char to remember the previous pwd
 *@param env_amb_list Linked list of the environment variables
 *@param env_token Linked list of metacharacters tokens
 *@param ast Abstract Syntax Tree
 *@param temp_env Linked list of temporary environment variables
*/
typedef struct s_mini_env
{
	int			fd_in;
	int			fd_out;
	int			exit_status;
	int			cmd_num;
	char		*cwd;
	char		*input;
	char		*prompt;
	char		**env;
	char		**senv;
	char		**path;
	int			**pipes;
	int			close_p;
	char		*oldpwd;
	t_list		*env_amb_list;
	t_list		*env_token;
	t_a_s_tree	*ast;
	t_list		*temp_env;
}			t_mini_env;

// ------------ MAIN ------------ //

void		mini_init(char	**env);
int			main(int argc, char **argv, char **envp);

// ------------ EXECVE ------------ //
char		**get_paths(void);
void		absolute_input(char **args);
void		exec_command(char **args);
char		*path_join(char *path, char *cm);

// ------------ USER ------------ //
char		*get_prompt(void);

// ----------- BUILT-INs ----------- //
int			minipdw(void);
void		printexp(int size);
int			mini_cd(char **args);
int			env_unset(char *args);
int			miniecho(char **args);
void		miniexit(char **args);
void		close_all_pipes(void);
int			miniunset(char **args);
void		mini_exit2(char **args);
int			built_type(char **args);
int			built_type_next(char **args);
void		minienv(t_list *env_amb_list);
void		sort_export(int i, int j, int size);
void		export_add(char *args, int flag, int i, int j);
void		miniexport(char **args, int flag, int i, int j);

// ----------- EXPORT_UTILS ----------- //
void		printexp(int size);
int			add_quo(t_env **lst);
t_env		*exp_alloc(char *args);
bool		exp_exists(char *args);
void		ft_list_remove_if(t_list **list, char *args, bool *found);

// ----------- INPUT_ANALYSIS ----------- //
void		input(void);
int			iseven(int s_trig);

// ----------- REDIRECTS ---------- //
int			redirects(t_meta_tok token, char *com);
int			heredoc(char *args);
void		hreader(char *args);
char		*hexpand(char *args);
char		*dollar_finder(char *args);
char		*process_char(char *args, int *i, char *result);
char		*extract_env_value(char *args, int *index);

// ------------ ERRORS ----------- //
int			err_handler(char c, char *cmd, int ext_sts);

// ----------- UTILS ----------- //
int			sz_env_list(char **env);
void		free_array(char **arr);
void		list_delete(void *list);
int			is_every_space(char *str);
int			ft_swap_env(char *swap, int i);
int			pars_error(char c, int ex_stat);
int			ft_strlen_skp(char *str, char *c);
char		**add_to_mat(char **mat1, char *str);
int			ft_strlen_flag(char const *str, char flag);

// ----------- UTILS2 ----------- //
void		fd_duplicate(void);
int			arr_size(char **str);
void		free_env(t_env **lst);
void		fd_close(int command_index);
bool		is_last_command(int command_numbers);
bool		is_built_in(char *command, char *arg);
char		*rm_quotes(char *arg);
void		ft_get_oldpwd(void);

// ---------- VARIABLE_GLOBAL ---------- //
t_mini_env	*mini_shell(void);

// ---------- ENV ---------- //
void		env_update(void);
char		*ft_get_env(char *type);

char		**env_to_mat(t_list *env_list);
char		**lst_to_mat(t_list *env_list);
char		*create_env_string(t_env *env);

// ---------- ENV_VAR_LIST ---------- //
t_list		*envlist(char **env);
t_env		*env_verif(t_list *env, char *type);
t_env		*new_env_list(char *type, char *info);
void		add_env_vars(t_list **envlist, char *container);

// ---------- INPUT_VERIF ---------- //
int			figure_out(void);
void		read_metachar(void);
bool		metacharacters_verif(void);
int			find_sym(char *quote, char *str);
bool		is_joinable(char *str, char *match, int skip);

// ---------- INPUT_VERIF2 ---------- //
bool		is_command(t_token *token);
bool		redirection(t_token *token);
bool		pipe_or_redir(t_token *token);
bool		pipe_or_not_hd(t_token *token);
t_token		*scanner(t_operations operations);
bool		input_analysis(int num_of_pipes, int num_of_commands);

// ---------- EXPANDER ---------- //
void		expander(void);
char		*find_key(char *str);
void		expand_variable(t_token *token);
char		*ft_streplace(char *str, char *old, char *new);

// ---------- FREE ---------- //
void		ft_free(void);
void		ft_free_all(void);
void		clean_env(t_env *env);
void		ft_clean(void *value);
void		clean_ast_tokens(t_a_s_tree *ast);
void		clean_a_s_tree(t_a_s_tree *ast, void (*del)(t_a_s_tree *));

// ---------- AST_TOKENS ---------- //
t_a_s_tree	*ast_new_token(t_token *token);
void		ast_insert(t_a_s_tree **ast, t_a_s_tree *node, bool left);

// ---------- PARSER ---------- //
void		parser(void);
t_a_s_tree	*parser_pipes(void);
t_a_s_tree	*parser_commands(void);
t_a_s_tree	*extend_command(t_a_s_tree *command);
t_a_s_tree	*extend_pipes(t_a_s_tree *ast, t_a_s_tree *command);

// ---------- SIGNALS ---------- //
void		signals(void);
void		child_signals(void);
void		ignore_signals(void);
void		heredoc_signals(void);

// ---------- HANDLE_SIGNALS ---------- //
void		handle_child(int signum);
void		handle_sigint(int signum);
void		handle_heredoc(int signum);
bool		metacharacters_verif(void);
void		read_metachar(void);

// ---------- TOKENS ---------- //
t_token		*copy_token(t_token *token);
void		destroy_token(t_token *token);
t_token		*new_token(char *str, t_meta_tok type, bool join);
int			conv_to_token(char *str, t_meta_tok type, bool joinable);

// ---------- EXECUTE ---------- //
void		execute(t_a_s_tree *ast);
pid_t		exec_is_fork(t_a_s_tree *command);

// ---------- PIPES ---------- //
void		pipes_generate(void);
pid_t		execute_pipes(t_a_s_tree *node);
void		atribute_pipes_fd(int index_command);

// ---------- VERIFS ---------- //
bool		builtin_verif(char *command);

#endif