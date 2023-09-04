/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:48:38 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/29 08:52:28 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_exitt(char *msg)
{
	(void)msg;
	ft_putstr_fd("bash: \n", 2);
	exit(1);
}

void	ft_ini_pip(t_pip *pip, t_data *p)
{
	int		i;

	i = 0;
	pip->num_of_process = ft_lstsize(p);
	pip->pid = malloc(sizeof(int) * pip->num_of_process);
	pip->fd = (int **)malloc((pip->num_of_process - 1) * sizeof(int *));
	pip->tmpfdin = dup(0);
	pip->tmpfdout = dup(1);
	while (i < pip->num_of_process - 1)
	{
		pip->fd[i] = (int *)malloc(2 * sizeof(int));
		if (pipe(pip->fd[i]) == -1)
			ft_exitt("error in pipe");
		i++;
	}
}

void	ft_close_fd(t_pip *pip)
{
	int	i;

	i = 0;
	while (i < pip->num_of_process - 1)
	{
		close(pip->fd[i][0]);
		close(pip->fd[i++][1]);
	}
}

void	ft_stand_inout(t_pip *pip)
{
	dup2(pip->tmpfdin, 0);
	dup2(pip->tmpfdout, 1);
}

//signal ------------------------------------------------
void	handle_sigfork(int sig)
{
	if (g_id.id == -4)
	{
		if (sig == SIGQUIT)
		{
			printf("Quit: 3\n");
			exit (g_id.id);
		}
		if (sig == SIGINT)
		{
			printf ("\n");
			exit (g_id.id);
		}
	}
}
