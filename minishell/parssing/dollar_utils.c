/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:09:52 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/29 00:08:00 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_join(char *s1, char *s2)
{
	char	*p;

	p = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	s1 = 0;
	s2 = 0;
	return (p);
}

t_dl	ft_d_statu(char *text, t_env *envlst, t_dl d)
{
	if (!d.str && d.i > 0)
		d.str = ft_join(d.str, ft_substr(text, 0, d.i));
	d.str = ft_join(d.str, ft_itoa(envlst->statexit));
	d.i++;
	d.j = d.i + 1;
	return (d);
}

t_dl	ft_sub_change_d(char *text, t_env *envlst, t_dl d)
{
	if (!d.str)
		d.str = ft_substr(text, 0, d.i);
	d.j = d.i + 1;
	while (text[d.j] && (ft_isalnum(text[d.j]) || text[d.j] == '_'))
		d.j++;
	d.str = ft_join(d.str, ft_strdup(ft_key(envlst, \
	ft_substr(text, d.i + 1, d.j - d.i - 1))));
	d.i = d.j - 1;
	return (d);
}
