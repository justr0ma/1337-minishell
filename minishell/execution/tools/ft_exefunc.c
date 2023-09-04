/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exefunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:50:39 by halaqoh           #+#    #+#             */
/*   Updated: 2022/09/03 23:44:44 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_execmd(t_env *envm, t_data *p, char **env)
{
	signal(SIGQUIT, handle_sigfork);
	signal(SIGINT, handle_sigfork);
	if (execve(patho(envm, p->cmd[0]), p->cmd, env) == -1)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
}

int	ft_exec_onecmd(t_pip *pip, t_data *p, t_env **envm, t_env **exp)
{
	g_id.id = 0;
	if (p->herd[0])
	{
		if (p->herfd && p->in == 2)
			dup2(p->herfd, 0);
		close(p->herfd);
	}
	if (!ft_redirection(p))
	{
		ft_stand_inout(pip);
		ft_pipclear(&pip);
		return (1);
	}
	if (!p->cmd[0])
		return (0);
	if (ft_normexec(envm, exp, p, pip))
		return (1);
	ft_stand_inout(pip);
	return (0);
}

void	ft_exec_checkred(t_pip *pip, int i, t_data *p)
{
	if (i == 0)
		dup2(pip->fd[0][1], 1);
	else if (i == pip->num_of_process - 1)
	{
		dup2(pip->fd[pip->num_of_process - 2][0], 0);
		dup2(pip->tmpfdout, 1);
	}
	else
	{
		dup2(pip->fd[i - 1][0], 0);
		dup2(pip->fd[i][1], 1);
	}
	if (p->herd[0])
	{
		if (p->herfd && p->in == 2)
			dup2(p->herfd, 0);
		close(p->herfd);
	}
	if (!ft_redirection(p))
	{
		ft_stand_inout(pip);
		ft_pipclear(&pip);
		return ;
	}
}

void	ft_exec_multcmd(t_pip *pip, t_data *p, t_env **envm, t_env **exp)
{
	if (check_builtins(envm, exp, p) != 0)
	{
		g_id.id = 0;
		dup2(pip->tmpfdin, 0);
		dup2(pip->tmpfdout, 1);
	}
	else
	{
		g_id.id = -4;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		pip->pid[pip->i] = fork();
		if (pip->pid[pip->i] == 0)
		{
			signal(SIGQUIT, handle_sigfork);
			signal(SIGINT, handle_sigfork);
			ft_close_fd(pip);
			if (execve(patho(*envm, p->cmd[0]), p->cmd, ft_exenv(*envm)) == -1)
			{
				ft_putstr_fd("command not found\n", 2);
				exit(127);
			}
		}
	}
}

void	ft_justr(t_pip *pip, t_env **envm)
{
	int	i;

	(void) envm;
	i = 0;
	ft_close_fd(pip);
	while (i < pip->num_of_process)
		waitpid(pip->pid[i++], &(g_id.id), 0);
	if (WIFSIGNALED(g_id.id))
		g_id.id += 128;
	else
		g_id.id = WEXITSTATUS(g_id.id);
	dup2(pip->tmpfdin, 0);
	dup2(pip->tmpfdout, 1);
	ft_pipclear(&pip);
}
