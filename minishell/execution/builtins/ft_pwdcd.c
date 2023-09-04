/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwdcd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:28:21 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/25 05:21:55 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_cd(char **argv)
{
	if (chdir(argv[1]))
	{
		ft_putstr_fd("bash: cd: No such file or directory\n", 2);
		g_id.id = 1;
	}
	return (1);
}

int	ft_pwd(void)
{
	char	cwd[556];

	if (getcwd(cwd, sizeof(cwd)) == 0)
		ft_putstr_fd("NULL", 2);
	else
		printf("%s\n", cwd);
	return (1);
}
