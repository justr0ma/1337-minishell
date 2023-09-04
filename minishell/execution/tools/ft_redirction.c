/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:42:02 by halaqoh           #+#    #+#             */
/*   Updated: 2022/09/03 23:14:56 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_redirection(t_data *p)
{
	int	j;
	int	fdinf;

	fdinf = 0;
	if (p->in == 1)
	{
		j = ft_redin(fdinf, p);
		if (j == 0)
			return (0);
		fdinf = open(p->inf[j - 1], O_RDONLY);
		dup2(fdinf, 0);
		close (fdinf);
	}
	ft_justredout(fdinf, p);
	j = ft_justapah(fdinf, p);
	if (p->out == 2)
	{
		fdinf = open(p->append[j - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		dup2(fdinf, 1);
		close (fdinf);
	}
	return (1);
}

int	ft_romafile(t_data *p, char *input, int fd, t_env *envlst)
{
	char	*tmp;

	while (ft_strncmp(p->herd[p->i], input, \
	ft_strlen(p->herd[p->i]) + 1) != 0)
	{
		tmp = ft_join(ft_d(ft_strdup(input), envlst, 0), ft_strdup("\n"));
		ft_putstr_fd(tmp, fd);
		free (tmp);
		free (input);
		input = readline("> ");
		if (input == 0)
			exit (0);
	}
	free (input);
	return (0);
}

int	ft_lastherdo(int fd, t_data *p, char *input, t_env *envlst)
{
	char	*tmp;

	if (p->herd[p->i + 1] == 0 && p->cmd[0])
	{
		tmp = ft_strjoin("/tmp/herdor", ft_itoa(p->pos));
		fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		ft_romafile(p, input, fd, envlst);
		close(fd);
		free(tmp);
		return (1);
	}
	return (0);
}

void	ft_herdo(t_data *p, t_env *envlst)
{
	int		i;
	int		fd;
	char	*input;

	i = 0;
	fd = 0;
	while (p->herd[i])
	{
		input = readline("> ");
		if (input == 0)
			exit (0);
		p->i = i;
		if (ft_lastherdo(fd, p, input, envlst))
			exit (0);
		while (ft_strncmp(p->herd[i], input, ft_strlen(p->herd[i]) + 1) != 0)
		{
			free (input);
			input = readline("> ");
			if (input == 0)
				exit (0);
		}
		free (input);
		i++;
	}
}
