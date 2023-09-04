/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:33:27 by halaqoh           #+#    #+#             */
/*   Updated: 2022/09/03 23:48:14 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_xp(t_env	**xp, char	**cmd, int i)
{
	t_env	*tmp;
	t_env	*current;

	tmp = *xp;
	if (ft_strncmp((*xp)->key, cmd[i], ft_strlen(cmd[i]) + 1) == 0)
	{
		*xp = (*xp)->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		return ;
	}
	while (tmp->next)
	{
		if (ft_strncmp(tmp->key, cmd[i], ft_strlen(cmd[i]) + 1) == 0)
			ft_lstdelone(current);
		current = tmp;
		tmp = tmp->next;
	}
	if (ft_strncmp(tmp->key, cmd[i], ft_strlen(cmd[i]) + 1) == 0)
		ft_lstdelone(current);
}

void	ft_en(t_env	**envm, char	**cmd, int i)
{
	t_env	*tmp;
	t_env	*current;

	tmp = *envm;
	if (ft_strncmp((*envm)->key, cmd[i], ft_strlen(cmd[i]) + 1) == 0)
	{
		*envm = (*envm)->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		return ;
	}
	while (tmp->next)
	{
		if (ft_strncmp(tmp->key, cmd[i], ft_strlen(cmd[i]) + 1) == 0)
			ft_lstdelone(current);
		current = tmp;
		tmp = tmp->next;
	}
	if (ft_strncmp(tmp->key, cmd[i], ft_strlen(cmd[i]) + 1) == 0)
		ft_lstdelone(current);
}

int	ft_unset(t_env	**xp, t_env	**envm, char	**cmd)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		ft_xp(xp, cmd, i);
		ft_en(envm, cmd, i);
		i++;
	}
	return (1);
}
