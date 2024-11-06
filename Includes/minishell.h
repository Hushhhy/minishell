/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:22:22 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/06 15:11:49 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/***********************/
/*  LIBRARIES IMPORTS  */
/***********************/

# include "../Libraries/pedro_lib/pedro_lib.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <stdio.h>
# include <stddef.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

/************************/
/*       DEFINES        */
/************************/

# define PROMPT_LINE "\1\033[1;91m\2MYSHELL=> \1\033[0m\2"

/************************/
/*       SIGNALS        */
/************************/

# define CTRL_C 130
# define CTRL_D 0
# define CTRL_BS 131

/************************/
/*    GLOBAL VARIABLE   */
/************************/

extern int	g_var;

/************************/
/*      STRUCTURES      */
/************************/

typedef struct s_var
{
	int		x;
	int		y;
}				t_var;

typedef struct s_exp
{
	size_t	x;
	bool	in_single_quote;
	bool	in_double_quote;
}				t_exp;

typedef struct s_hw
{
	int		i;
	char	quote;
	bool	in_quotes;
	char	*tmp;
}				t_hw;

typedef enum s_token_type
{
	CMD,
	ARG,
	WORD,
	PIPE,
	INFILE,
	OUTFILE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND,
	LIMITER,
}				t_token_type;

typedef struct s_token
{
	char			*value;
	bool			to_del;
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

typedef struct s_env
{
	char			*name;
	char			*value;
	int				equal_sign;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_redirs
{
	char			*infile;
	bool			in_flag;
	bool			hd_flag;
	char			*outfile;
	bool			out_flag;
	bool			out_app;
	struct s_redirs	*next;
	struct s_redirs	*prev;
}				t_redirs;

typedef struct s_cmd
{
	t_token		*tok;
	char		**cmds;
	t_redirs	*redirs;
}				t_cmd;

typedef struct s_cmdline
{
	t_cmd				*cmd;
	struct s_cmdline	*next;
	struct s_cmdline	*prev;
}				t_cmdline;

typedef struct s_wdb
{
	int			x;
	int			status;
	int			*exit_status;
	t_cmdline	*current;
}				t_wdb;

typedef struct s_ms
{
	char		*prompt;
	char		**envi;
	pid_t		pipefd[2];
	int			*pid;
	int			previous_fd;
	t_env		*env;
	t_token		*tokens;
	t_cmdline	*cmdlines;
	int			v_return;
	int			c_count;
	bool		b;
	bool		hd;
	int			here_doc_fd;
}				t_ms;

typedef struct s_export
{
	t_env	*t_node;
	char	*name;
	char	*value;
	t_env	*new;
}			t_export;

/************************/
/*	    PROTOTYPES	    */
/************************/

//MINISHELL

//----------The program----------//

t_ms			*init_ms(void);
t_ms			*init_program(char **env);
char			*prompt(t_ms *ms);
void			the_program(t_ms *ms);

//-----------Signals-------------//

void			handle_sigint_hd(int sig);
void			handle_sigint(int sig);
void			child_sigint(int sig);
void			ft_sigquit_child(int sig);
int				handle_ctrld(t_ms *ms);

//-----Pre_parser functions------//

bool			q_check(char *s);
bool			is_quoted(char *s, int index);
bool			c_check(char *s);
bool			shit_check_1(char *s);
bool			_redirs_checker(t_ms *ms);
bool			full_check(t_ms *ms);
void			false_redirs(t_ms *ms);

//---------Env funtions----------//

t_env			*find_lastv(t_env *env);
int				find_equal_sign(char *s);
void			add_env(t_env **tok, char *value);
t_env			*init_env(char **env);
void			delete_env(t_env **head, t_env *node_to_del);
void			free_env(t_env **head);
t_env			*create_env(void);
void			add_create(t_env **env, char *name, char *value);
t_env			*init_create(char *name, char *value);

//--------Lexer functions--------//

bool			is_separator(char c, char next_c);
bool			is_quote(char c);
bool			is_space(char c);
int				token_counter(t_token *tok);
t_token			*find_last(t_token *tok);
t_token			*init_token(char *value);
void			add_token(t_token **tok, char *value);
t_token_type	da_tok(char *s, t_token *previous);
t_token			*lexer(char *input);
void			delete_token(t_token **head, t_token *node_to_del);
void			free_tokens(t_token **head);

//-------Expander functions------//

void			maybe_del_node(t_token *tok, t_env *env);
void			init_var(t_var *v);
char			*malloc_calculator(t_token *tok, t_env *env, int v_return);
char			*tracker(char *s, int *x);
void			transformer(t_token *tok, char *fs);
void			double_dollar(char *fs, int *x, int *y);
void			dollar_bruh(char *fs, int *x, int *y, int v_return);
bool			expandable(const char *str, size_t pos);
t_env			*find_node(char *s, t_env *env);
void			expand_variable(t_token *tok, t_env *env, t_var *v, char *fs);
char			*process_token_value(t_token *tok,
					t_env *env, int v_return, char *fs);
void			dr_kron(t_token *tok, t_env *env, int v_return);
void			finishing(t_token *tok);
void			remove_quotes(char *str);
void			expander(t_ms *ms);

//------------Builtins-----------//

int				builtins(t_ms *ms);
int				builtins_part(t_ms *ms, t_cmdline *current);
int				builtins_checker(t_ms *ms);
int				mini_builtins(t_ms *ms);
int				mini_builtins_parts(t_ms *ms, t_cmdline *current);
int				ft_echo(t_cmdline *cmdline);
bool			only_n(char *s);
int				ft_cd(t_cmdline *cmdline, t_ms *ms);
int				changedir(char *path, t_ms *ms);
int				print_env(t_cmdline *cmdline, t_ms *ms);
int				ft_exit(t_cmdline *cmdline, t_ms *ms);
int				is_num(const char *str);
int				ft_export(t_ms *ms);
char			*find_value(char *str);
int				process_export(t_ms *ms, t_export *exp, char *cmd,
					int *equal_sign);
char			*export_error(char *str);
void			print_export(t_env *env);
void			add_new(t_env **env, char *name, char *value, int equal_sign);
t_env			*init_exp_node(char *name, char *value, int equal_sign);
char			*find_name(char *str, int *equal_sign);
t_env			*find_env(t_env *env, const char *find);
void			no_args(t_env *env);
void			swap_list(t_env *a, t_env *b);
void			alr_exist(t_env *exist, char *value, int equal_sign);
char			*get_env_pwd(char *name, t_ms *ms);
int				ft_pwd(t_ms *ms);
char			*get_cwd(t_ms *ms);
int				ft_unset(t_ms *ms);

//------------Here doc-----------//

void			clean_hd_child(t_ms *ms);
void			close_all_fds(void);
void			delete_tmp_files(void);
char			*find_tmp_filename(void);
void			eof_display(char *limiter);
char			*create_filename(void);
void			here_doc_count(t_ms *ms, t_token *tok);
int				open_file(t_ms *ms, char *filename);
char			*handle_null_line(t_ms *ms, char *filename, char *limiter);
void			write_line_to_file(t_ms *ms, char *line);
int				check_line_against_limiter(char *line, char *limiter);
void			handle_here_doc(t_ms *ms, t_token **tokens);
void			save_std(int saved_stdin);

//-------------Exec--------------//

int				env_counter(t_env *env);
char			**the_env(t_env *env);
void			init_rs(t_redirs *redirs, t_token *tok);
void			clear_redirs_list(t_redirs **redirs);
void			add_redirs_node(t_redirs **redirs, t_token *tok);
t_redirs		*the_redirs(t_token *tok);

char			**the_cmds(t_token *tok);
void			init_cmd(t_cmdline *cmdline);
void			clear_cmdlines(t_cmdline **head);
void			add_cmdline_node(t_cmdline **cmdline, t_token *tok);
void			the_cmdlines(t_ms *ms);

void			redirect_and_close(int fd, int std_fd);
void			_maybe_fd_closing(int fd);

int				cmdlines_counter(t_cmdline *cmdline);
void			handle_exec_error(t_ms *ms);
void			ft_open_files(t_ms *ms);
void			redirector(t_ms *ms);
char			*env_for_exec(char **envi, char *cmd);
char			*cmd_path(char **envi, char *cmd, t_ms *ms);
void			cmd_exec(t_ms *ms, char *cmd);
int				wait_da_boy(t_ms *ms);
int				waiting_(t_ms *ms, int v_ret);
void			child_process(t_ms *ms);
int				executioner(t_ms *ms);
int				executor(t_ms *ms);
void			close_and_free(t_ms *ms);

//------------Cleaning-----------//

void			clean_child(t_ms *ms);
void			clear_program(t_ms *ms);
void			clear_program_hd(t_ms *ms);

#endif
