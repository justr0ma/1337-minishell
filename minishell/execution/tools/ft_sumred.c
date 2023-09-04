/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumred.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:41:54 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/24 18:44:59 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_redin(int fdinf, t_data	*p)
{
	int	j;

	j = 0;
	while (p->inf[j])
	{
		fdinf = open(p->inf[j], O_RDONLY);
		if (fdinf < 0)
		{
			printf("%s: No such file or directory\n", p->inf[j]);
			return (0);
		}
		close (fdinf);
		j++;
	}
	return (j);
}

int	ft_justapah(int fdinf, t_data	*p)
{
	int	j;

	j = 0;
	while (p->append[j])
	{
		fdinf = open(p->append[j], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (fdinf < 0)
		{
			printf("%s: No such file or directory\n", p->append[j]);
			return (0);
		}
		close (fdinf);
		j++;
	}
	return (j);
}

int	ft_justredout(int fdinf, t_data *p)
{
	int	j;

	j = 0;
	while (p->outf[j])
	{
		fdinf = open(p->outf[j], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fdinf < 0)
			return (0 * printf("%s: No such file or directory 1\n", p->outf[j]));
		close (fdinf);
		j++;
	}
	if (p->out == 1)
	{
		fdinf = open(p->outf[j - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(fdinf, 1);
		close (fdinf);
	}
	return (0);
}
