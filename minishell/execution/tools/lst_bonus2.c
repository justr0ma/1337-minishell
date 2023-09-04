/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bonus2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:28:03 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/29 06:43:13 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lstdelone(t_env *lst)
{
	t_env	*tmp;

	tmp = (lst)->next;
	lst->next = (lst)->next->next;
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}

void	ft_justlast(t_env	*tmp, t_env	*t)
{
	char	*romakey;
	char	*romavalue;

	while (tmp->next)
	{
		if (ft_strncmp(t->key, tmp->key, ft_strlen(t->key)) < 0)
		{
			romakey = t->key;
			romavalue = t->value;
			t->key = tmp->key;
			t->value = tmp->value;
			tmp->key = romakey;
			tmp->value = romavalue;
		}
		tmp = tmp->next;
	}
}

void	ft_sortexport(t_env	**xp, char *romakey, char *romavalue)
{
	t_env	*tmp;
	t_env	*t;

	tmp = *xp;
	t = *xp;
	while (t->next)
	{
		tmp = *xp;
		while (tmp->next)
		{
			if (ft_strncmp(t->key, tmp->key, ft_strlen(t->key)) < 0)
			{
				romakey = t->key;
				romavalue = t->value;
				t->key = tmp->key;
				t->value = tmp->value;
				tmp->key = romakey;
				tmp->value = romavalue;
			}
			tmp = tmp->next;
		}
		t = t->next;
	}
	tmp = *xp;
	ft_justlast(tmp, t);
}

void	ft_printlist(t_env	**xp, int i)
{
	t_env	*tmp;
	char	*romakey;
	char	*romavalue;

	romakey = 0;
	romavalue = 0;
	ft_sortexport(xp, romakey, romavalue);
	if (i == 1)
	{
		tmp = *xp;
		while (tmp)
		{
			printf("declare -x %s=\"", tmp->key);
			if (tmp->value)
				printf("%s\"\n", tmp->value);
			tmp = tmp->next;
		}
	}
}
