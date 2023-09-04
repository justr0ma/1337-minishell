/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 04:29:21 by halaqoh           #+#    #+#             */
/*   Updated: 2022/09/03 23:41:29 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_justnorm(int pid, t_data *tmp, int pos)
{
	char	*file;

	waitpid(pid, &(g_id.id), 0);
	signal(SIGINT, handle_sigint);
	if (WEXITSTATUS(g_id.id))
		g_id.id = 1;
	else if (WIFSIGNALED(g_id.id))
	{
		g_id.id = WIFSIGNALED(g_id.id);
		return (1);
	}
	else
	{
		while (tmp)
		{
			if (tmp->herd[0] && tmp->cmd[0])
			{
				file = ft_join(ft_strdup("/tmp/herdor"), ft_itoa(pos++));
				tmp->herfd = open(file, O_RDONLY);
				free (file);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

int	ft_ghostherdo(t_data *p, t_env *envm)
{
	t_data	*tmp;
	int		pos;
	int		pid;

	tmp = p;
	pos = 0;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_DFL);
		while (tmp)
		{
			tmp->herfd = 0;
			tmp->pos = pos++;
			ft_herdo(tmp, envm);
			tmp = tmp->next;
		}
		exit (0);
	}
	if (ft_justnorm(pid, tmp, pos))
		return (1);
	return (0);
}

void	ft_dyalft(t_data *p, t_env **envm, t_env **exp, t_pip *pip)
{
	ft_exec_checkred(pip, pip->i, p);
	ft_exec_multcmd(pip, p, envm, exp);
}

//main function -------------------------------------------
int	ft_execprocess(t_data *p, t_env	**envm, t_env **exp)
{
	t_pip	*pip;
	int		j;

	if (ft_ghostherdo(p, *envm))
		return (1);
	pip = malloc(sizeof(t_pip));
	ft_ini_pip(pip, p);
	pip->i = 0;
	while (p)
	{
		j = 0;
		if (pip->num_of_process == 1)
		{
			if (ft_exec_onecmd(pip, p, envm, exp) == 1)
				return (1);
		}
		else
		{
			ft_dyalft(p, envm, exp, pip);
			pip->i++;
		}
		p = p->next;
	}
	ft_justr(pip, envm);
	return (1);
}
