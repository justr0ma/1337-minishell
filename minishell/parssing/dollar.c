/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:23:21 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/29 00:06:56 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_d(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (0);
	return (1);
}

char	*ft_key(t_env *envlst, char *key)
{
	t_env	*tmp;

	tmp = envlst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key) + 1))
		{
			free(key);
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	free(key);
	return (ft_strdup(""));
}

t_dl	ft_change_d(char *text, t_env *envlst, t_dl d)
{
	if (text[d.i + 1] == '?')
		d = ft_d_statu(text, envlst, d);
	else if (check_d(text[d.i + 1]))
	{
		if (!d.str)
			d.str = ft_substr(text, 0, d.i + 1);
		else
			d.str = ft_join(d.str, ft_substr(text, d.j, d.i + 1 - d.j));
		d.j = d.i + 1;
	}
	else
		d = ft_sub_change_d(text, envlst, d);
	if (text[d.i] && !ft_strchr(text + d.i + 1, '$'))
		d.str = ft_join(d.str, ft_strdup(text + d.i + 1));
	else
	{
		if (text[d.i] && text[d.i] != '$')
		{
			while (text[d.i + 1] != '$')
				d.i++;
			d.str = ft_join(d.str, ft_substr(text, d.j, d.i + 1 - d.j));
			d.j = d.i + 1;
		}
	}
	return (d);
}

char	*ft_d(char *text, t_env *envlst, char check)
{
	t_dl	d;

	d.i = 0;
	d.str = 0;
	d.j = 0;
	if (ft_strchr(text, '$') && check != '\'')
	{
		while (text[d.i])
		{
			if (text[d.i] == '$')
				d = ft_change_d(text, envlst, d);
			if (text[d.i])
				d.i++;
		}
		free(text);
		return (d.str);
	}
	return (text);
}
