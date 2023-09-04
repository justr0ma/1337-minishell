/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 02:11:17 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/29 06:16:15 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_env	*ft_check_key(char *str, t_env *xp)
{
	t_env	*tmpxp;
	char	*tmp;

	tmpxp = xp;
	if (ft_strchr(str, '+'))
		tmp = ft_substr(str, 0, ft_strlen(str) - 1);
	else
		tmp = ft_strdup(str);
	while (tmpxp && ft_strncmp((tmpxp)->key, tmp, ft_strlen(tmp) + 1) != 0)
		tmpxp = tmpxp->next;
	free (tmp);
	return (tmpxp);
}

void	ft_addxp(char **cmd, t_env **envm, t_env **xp, int i)
{
	char	**cmds;
	t_env	*tmpxp;

	cmds = ft_split(cmd[i], '=');
	tmpxp = ft_check_key(cmds[0], *xp);
	if (!ft_strchr(cmd[i], '=') && tmpxp)
		printf("");
	else if (tmpxp)
		ft_roma_code(envm, tmpxp, cmds, cmd[i]);
	else
		ft_justadd(cmd[i], xp, envm, cmds);
	ft_free_str(cmds);
}
