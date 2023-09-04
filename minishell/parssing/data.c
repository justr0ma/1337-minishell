/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:59:03 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/22 05:33:18 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// resero (int count[5]) from data struct to 1
void	ft_resero(t_data **data)
{
	int	i;

	i = 0;
	while (i < 5)
		(*data)->ct[i++] = 1;
}

// count and malloc for data -------------------------------------------------
void	ft_matchcount(t_data **data)
{
	ft_dlast(*data)->cmd = malloc(sizeof(char *) * ft_dlast(*data)->ct[CMD]);
	ft_dlast(*data)->inf = malloc(sizeof(char *) * \
	ft_dlast(*data)->ct[RED_IN]);
	ft_dlast(*data)->outf = malloc(sizeof(char *) * \
	ft_dlast(*data)->ct[RED_OUT]);
	ft_dlast(*data)->append = malloc(sizeof(char *) * \
	ft_dlast(*data)->ct[APPEND]);
	ft_dlast(*data)->herd = malloc(sizeof(char *) * \
	ft_dlast(*data)->ct[HERD]);
	if (!ft_dlast(*data)->cmd || !ft_dlast(*data)->inf || \
	!ft_dlast(*data)->outf || !ft_dlast(*data)->append || \
	!ft_dlast(*data)->herd)
		exit(EXIT_FAILURE);
	ft_dlast(*data)->cmd[0] = 0;
	ft_dlast(*data)->inf[0] = 0;
	ft_dlast(*data)->outf[0] = 0;
	ft_dlast(*data)->append[0] = 0;
	ft_dlast(*data)->herd[0] = 0;
}

void	ft_takespace(t_list **mini, t_data **data)
{
	t_list	*tmp;

	tmp = *mini;
	(*data) = ft_datanew();
	while (tmp)
	{
		while (tmp && tmp->tok != PIPE)
		{
			ft_dlast(*data)->ct[tmp->tok] += ft_cmdsize(tmp->cmd);
			tmp = tmp->next;
		}
		ft_matchcount(data);
		if (tmp)
		{
			ft_dtadd(data, ft_datanew());
			tmp = tmp->next;
		}
	}
}

// fill with data from list ---------------------------------------------

void	ft_dt_lst(t_list **lst, t_data **dt)
{
	if ((*lst)->tok == CMD)
		(*dt)->ct[CMD] = ft_mdt((*dt)->cmd, (*lst)->cmd, (*dt)->ct[CMD]);
	else if ((*lst)->tok == RED_IN)
		(*dt)->ct[RED_IN] = ft_mdt((*dt)->inf, (*lst)->cmd, (*dt)->ct[RED_IN]);
	else if ((*lst)->tok == RED_OUT)
		(*dt)->ct[RED_OUT] = ft_mdt((*dt)->outf, \
		(*lst)->cmd, (*dt)->ct[RED_OUT]);
	else if ((*lst)->tok == APPEND)
		(*dt)->ct[APPEND] = ft_mdt((*dt)->append, \
		(*lst)->cmd, (*dt)->ct[APPEND]);
	else if ((*lst)->tok == HERD)
		(*dt)->ct[HERD] = ft_mdt((*dt)->herd, (*lst)->cmd, (*dt)->ct[HERD]);
}

void	ft_datafill(t_list **mini, t_data **data)
{
	t_data	*dt;
	t_list	*lst;

	dt = *data;
	lst = *mini;
	while (dt && lst)
	{
		ft_resero(&dt);
		while (lst && lst->tok != PIPE)
		{
			ft_dt_lst(&lst, &dt);
			lst = lst->next;
		}
		dt = dt->next;
		if (lst)
			lst = lst->next;
	}
	ft_prio(*mini, data);
}
