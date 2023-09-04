/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:27:45 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/16 23:05:20 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_env	*ft_lstnew(char *key, char *value)
{
	t_env	*p;

	p = NULL;
	p = (t_env *)malloc(sizeof(t_env));
	if (!p)
		return (0);
	p->key = key;
	if (value)
		p->value = value;
	else
		p->value = ft_strdup("");
	p->next = NULL;
	return (p);
}

t_env	*ft_lstlast(t_env *lst)
{
	t_env	*n;
	t_env	*current;

	n = lst;
	current = NULL;
	while (n)
	{
		current = n;
		n = n->next;
	}
	return (current);
}

void	ft_lstadd_front(t_env **lst, t_env *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

int	ft_lstsize(t_data *lst)
{
	int		i;
	t_data	*n;

	i = 0;
	n = lst;
	while (n)
	{
		n = n->next;
		i++;
	}
	return (i);
}
