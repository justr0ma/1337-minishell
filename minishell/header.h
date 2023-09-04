/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:43:27 by abouhmad          #+#    #+#             */
/*   Updated: 2022/09/03 23:44:05 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

// # include <cstddef> // nedded for NULL (new)
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <signal.h>
# include <regex.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

enum e_title
{
	CMD,
	RED_IN,
	RED_OUT,
	APPEND,
	HERD,
	PIPE
};

typedef struct s_id
{
	int	id;
}t_id;

t_id	g_id;

typedef struct s_cmd
{
	char			*content;
	struct s_cmd	*next;
}t_cmd;

typedef struct s_list
{
	int				tok;
	t_cmd			*cmd;
	struct s_list	*next;
}t_list;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				statexit;
	struct s_env	*next;
}t_env;

typedef struct s_var
{
	int				i;
	int				check;
}t_var;

typedef struct s_dollar
{
	char		*str;
	int			i;
	int			j;
}t_dl;

typedef struct s_data
{
	char			**cmd;
	char			**inf;
	char			**outf;
	char			**append;
	char			**herd;
	int				error;
	int				*ct;
	int				herfd;
	int				pos;
	int				i;
	int				in;
	int				out;
	struct s_data	*next;
}t_data;

//pipe
typedef struct f
{
	int		**fd;
	int		*pid;
	int		num_of_process;
	int		tmpfdin;
	int		tmpfdout;
	int		i;
}t_pip;

//src -----------------------------------------------------------------

//List *****************
void	ft_lstadd(t_list **lst, t_list *new);
t_list	*ft_lnew(int tok, t_cmd *cmd);
t_list	*ft_llast(t_list *lst);
void	ft_lstclear(t_list **lst);

//List > cmd ______
void	ft_cmdadd(t_cmd **lst, t_cmd *new);
t_cmd	*ft_cnew(char *content);
int		ft_cmdsize(t_cmd *lst);
t_cmd	*ft_clast(t_cmd *lst);

//List > env
void	ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_envlast(t_env *lst);
int		ft_envsize(t_env *lst);
t_env	*ft_enew(char *key, char *value);

//List > data
t_data	*ft_dlast(t_data *lst);
t_data	*ft_datanew(void);
void	ft_dtadd(t_data **lst, t_data *new);
void	ft_dataclear(t_data **data);
void	ft_free_str(char **str);//new---------
//----------------------------------------------------------------------

//Main functions --------------------
void	fill_env(t_env **envlst, t_env **exp, char **env);//modif add exp
void	parsser(char *line, t_data **data, t_env *envlst, t_list **mini);
void	ft_takespace(t_list **mini, t_data **data);
void	ft_datafill(t_list **mini, t_data **data);

//Is functions ---------------------
int		is_space(char c);
int		is_sprt(char c);
int		is_redi(t_list **mini);
int		is_qt(char c);
int		is_special(char c);

//Get functions --------------------
int		get_cmd(char *line, int start, t_list **mini, t_env *envlst);
int		get_file(char *line, t_var var, t_list **mini, t_env *envlst);
int		get_text(char *line, t_var var, t_list **mini, t_env *envlst);
void	ft_redi(char *line, int i, t_list **mini, char check);

//Data utils functions --------------
int		ft_mdt(char **str, t_cmd *lst, int i);
void	ft_prio(t_list *mini, t_data **data);

//Dollor $ functions ----------------
t_dl	ft_sub_change_d(char *text, t_env *envlst, t_dl d);
t_dl	ft_d_statu(char *text, t_env *envlst, t_dl d);
char	*ft_d(char *text, t_env *envlst, char check);
char	*ft_key(t_env *envlst, char *key);
char	*ft_join(char *s1, char *s2);
int		check_d(char c);

//Error functions -------------------
int		ft_syntax_error(char *line, t_list **mini, char check);
int		ft_check_pipe(t_list **mini, char *line, int i);
void	ft_last_pipe(t_list **mini);

//I'm here exection =============>

void	ft_lstadd_back(t_env **lst, t_env *new);
t_env	*ft_lstnew(char *key, char *value);
void	ft_lstdelone(t_env *lst);
int		ft_lstsize(t_data *lst);
t_env	*ft_lstlast(t_env *lst);

void	ft_roma_code(t_env	**envm, t_env	*tmpxp, char **cmds, char *cmd);
void	ft_justadd(char *cmd, t_env **xp, t_env **envm, char **cmds);
void	ft_addxp(char **cmd, t_env **envm, t_env **xp, int i);
int		check_builtins(t_env **envm, t_env **xp, t_data *p);
int		ft_execprocess(t_data *p, t_env	**envm, t_env **exp);
void	ft_just_snorme(t_env *tev, char *key, char *cmd, t_env **envm);
int		ft_export(char **cmd, t_env **envm, t_env **xp);
t_env	*ft_check_key(char *str, t_env *xp);
int		ft_unset(t_env **xp, t_env	**envm, char **cmd);
void	ft_herdo(t_data *p, t_env *envlst);
char	*ft_getenv(char *va, t_env *envm);
int		ft_echo(t_data	*p, char **argv);
char	*patho(t_env *envm, char *args);
int		ft_redirection(t_data *p);
int		ft_envi(t_env *envm);
int		ft_strchrp(char *s);
void	ft_exitt(char *msg);
int		ft_exit(char **cmd);
int		ft_cd(char **argv);
int		ft_pwd(void);

void	ft_exec_multcmd(t_pip *pip, t_data *p, t_env **envm, t_env **exp);
int		ft_exec_onecmd(t_pip *pip, t_data *p, t_env **envm, t_env **exp);
int		ft_normexec(t_env **envm, t_env **exp, t_data *p, t_pip *pip);
void	ft_exec_checkred(t_pip *pip, int i, t_data *p);
void	ft_execmd(t_env *envm, t_data *p, char **env);
void	ft_justr(t_pip *pip, t_env **envm);
void	ft_ini_pip(t_pip *pip, t_data *p);
void	ft_printlist(t_env	**xp, int i);
void	ft_stand_inout(t_pip *pip);
void	ft_pipclear(t_pip **data);
int		ft_redirection(t_data *p);
void	ft_close_fd(t_pip *pip);
char	**ft_exenv(t_env *envm);

//signal functions ----------------->
int		ft_justredout(int fdinf, t_data *p);
int		ft_justapah(int fdinf, t_data	*p);
int		ft_redin(int fdinf, t_data	*p);
void	handle_sigfork(int sig);
void	handle_sigint(int sig);

#endif
