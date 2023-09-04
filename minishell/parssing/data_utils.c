/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 07:13:19 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/22 05:47:47 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Match data from mini
int	ft_mdt(char **str, t_cmd *lst, int i)
{
	while (lst)
	{
		str[i - 1] = ft_strdup(lst->content);
		str[i] = NULL;
		lst = lst->next;
		i++;
	}
	return (i);
}

// Priority of redirection

void	ft_prio(t_list *mini, t_data **data)
{
	t_list	*tmp;
	t_data	*tmp2;

	tmp = mini;
	tmp2 = *data;
	while (tmp && tmp2)
	{
		while (tmp && tmp->tok != PIPE)
		{
			if (tmp->tok == RED_IN)
				tmp2->in = 1;
			else if (tmp->tok == HERD)
				tmp2->in = 2;
			else if (tmp->tok == RED_OUT)
				tmp2->out = 1;
			else if (tmp->tok == APPEND)
				tmp2->out = 2;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
		if (tmp)
			tmp = tmp->next;
	}
}
