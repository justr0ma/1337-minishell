/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:45:39 by halaqoh           #+#    #+#             */
/*   Updated: 2022/09/03 23:22:45 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	check_builtins(t_env **envm, t_env **xp, t_data	*p)
{
	if (p->cmd[0])
	{
		if (!strncmp(p->cmd[0], "echo", 5))
			return (ft_echo(p, p->cmd));
		else if (!strncmp(p->cmd[0], "cd", 3))
			return (ft_cd(p->cmd));
		else if (!strncmp(p->cmd[0], "pwd", 4))
			return (ft_pwd());
		else if (!strncmp(p->cmd[0], "export", 7))
			return (ft_export(p->cmd, envm, xp));
		else if (!strncmp(p->cmd[0], "unset", 6))
			return (ft_unset(xp, envm, p->cmd));
		else if (!strncmp(p->cmd[0], "env", 4))
			return (ft_envi(*envm));
		else if (!strncmp(p->cmd[0], "exit", 5))
			return (ft_exit(p->cmd));
	}
	return (0);
}
