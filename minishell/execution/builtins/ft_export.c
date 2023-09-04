/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:31:25 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/29 07:00:25 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_just_snorme(t_env *tev, char *key, char *cmd, t_env **envm)
{
	char	*tmp;

	if (tev)
	{
		tmp = tev->value;
		tev->value = ft_strdup(ft_strchr(cmd, '='));
		free (tmp);
	}
	else
		ft_envadd_back(envm, ft_enew(ft_strdup(key), \
		ft_strdup(ft_strchr(cmd, '='))));
}

void	ft_roma_code(t_env	**envm, t_env	*tmpxp, char **cmds, char *cmd)
{
	char	*tmp;
	t_env	*tev;

	tev = *envm;
	while (tev && ft_strncmp((tev)->key, cmds[0], ft_strlen((tev)->key)) != 0)
		tev = tev->next;
	if (ft_strchr(cmds[0], '+'))
	{
		tmpxp->value = ft_join(tmpxp->value, ft_strdup(ft_strchr(cmd, '=')));
		if (tev)
			tev->value = ft_join(tev->value, ft_strdup(ft_strchr(cmd, '=')));
		else
			ft_envadd_back(envm, ft_enew(ft_strdup(tmpxp->key), \
			ft_strdup(tmpxp->value)));
	}
	else
	{
		tmp = tmpxp->value;
		tmpxp->value = ft_strdup(ft_strchr(cmd, '='));
		if (tmp)
			free(tmp);
		ft_just_snorme(tev, tmpxp->key, cmd, envm);
	}
}

void	ft_justadd(char *cmd, t_env **xp, t_env **envm, char **cmds)
{
	char	*vl;

	vl = ft_strchr(cmd, '=');
	if (vl)
		ft_envadd_back(xp, ft_enew(ft_strdup(cmds[0]), \
		ft_strdup(ft_strchr(cmd, '='))));
	else
		ft_envadd_back(xp, ft_enew(ft_strdup(cmds[0]), ft_strdup("")));
	if (ft_strchr(cmd, '='))
		ft_envadd_back(envm, ft_enew(ft_strdup(cmds[0]), \
		ft_strdup(ft_strchr(cmd, '='))));
}

int	ft_exp_isok(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || str[0] == '=')
		return (0);
	while (str[i] && str[i] != '=' && str[i] != '+')
	{
		if ((!ft_isalpha(str[0]) && str[0] != '_'))
			return (0);
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] == '+' && str[i + 1] != '=')
		return (0);
	return (1);
}

int	ft_export(char **cmd, t_env	**envm, t_env **xp)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (ft_exp_isok(cmd[i]))
			ft_addxp(cmd, envm, xp, i);
		else
		{
			g_id.id = 1;
			ft_putstr_fd("bash: export: not a valid identifier\n", 2);
		}
		i++;
	}
	ft_printlist(xp, i);
	return (1);
}
