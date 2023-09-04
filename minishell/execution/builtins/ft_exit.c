/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:40:19 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/31 22:45:34 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_exit_re(char *roma)
{
	int	i;
	int	rt;

	i = 0;
	while (roma[i])
	{
		if (!ft_isdigit(roma[i++]))
		{
			ft_putstr_fd("exit\nbash: exit: numeric argument required\n", 2);
			return (255);
		}
	}
	rt = ft_atoi(roma);
	if (rt < 256)
		return (rt);
	while (rt > 255)
		rt -= 256;
	return (rt);
}

int	ft_exit(char **cmd)
{
	int	i;

	if (cmd[2])
	{
		i = 0;
		while (cmd[1][i])
		{
			if (!ft_isdigit(cmd[1][i++]))
			{
				ft_putstr_fd("exit\nbash: exit: numeric argument required\n", 2);
				exit (255);
			}
		}
		ft_putstr_fd("exit\nbash: exit: too many arguments\n", 2);
		g_id.id = 1;
		return (1);
	}
	if (cmd[1])
		exit(ft_exit_re(cmd[1]));
	else
		exit (0);
}
