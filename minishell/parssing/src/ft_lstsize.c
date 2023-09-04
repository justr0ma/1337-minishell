/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:39:22 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/20 05:41:03 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// int	ft_lstsize(t_list *lst)
// {
// 	size_t	sz;

// 	sz = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		sz++;
// 	}
// 	return (sz);
// }

int	ft_cmdsize(t_cmd *lst)
{
	size_t	sz;

	sz = 0;
	while (lst)
	{
		lst = lst->next;
		sz++;
	}
	return (sz);
}

int	ft_envsize(t_env *lst)
{
	size_t	sz;

	sz = 0;
	while (lst)
	{
		lst = lst->next;
		sz++;
	}
	return (sz);
}
