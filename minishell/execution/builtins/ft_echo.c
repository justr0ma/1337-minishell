/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:20:54 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/22 04:00:42 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_roma(char **argv, int i)
{
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
		if (argv[i])
			printf(" ");
	}
}

int	ft_echo(t_data	*p, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (p->cmd[j])
		j++;
	if (j > 1)
	{
		if (!strncmp(argv[1], "-n", 2))
			i++;
		ft_roma(argv, i);
		if (strncmp(argv[1], "-n", 2))
			printf("\n");
	}
	else
		printf("\n");
	return (1);
}
