/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:48:40 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/20 20:31:40 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmpl;
	t_cmd	*tmpc;

	if (!lst)
		return ;
	while (*lst)
	{
		tmpl = (*lst)->next;
		while ((*lst)->cmd)
		{
			tmpc = (*lst)->cmd->next;
			free((*lst)->cmd->content);
			free((*lst)->cmd);
			(*lst)->cmd = tmpc;
		}
		free(*lst);
		*lst = tmpl;
	}
	*lst = 0;
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_dataclear(t_data **data)
{
	t_data	*tmp;
	int		i;

	tmp = *data;
	while (*data)
	{
		tmp = (*data)->next;
		i = 0;
		ft_free_str((*data)->cmd);
		ft_free_str((*data)->inf);
		ft_free_str((*data)->outf);
		ft_free_str((*data)->append);
		ft_free_str((*data)->herd);
		free((*data)->ct);
		free(*data);
		*data = tmp;
	}
	*data = 0;
}

void	ft_pipclear(t_pip **pipe)
{
	int	i;

	i = 0;
	while (i < (*pipe)->num_of_process - 1)
		free((*pipe)->fd[i++]);
	free((*pipe)->fd);
	free((*pipe)->pid);
	free(*pipe);
}

/* 
while ((*data)->cmd[i])
	free((*data)->cmd[i++]);
free((*data)->cmd);
i = 0;
while ((*data)->inf[i])
	free((*data)->inf[i++]);
free((*data)->inf);
i = 0;
while ((*data)->outf[i])
	free((*data)->outf[i++]);
free((*data)->outf);
i = 0;
while ((*data)->append[i])
	free((*data)->append[i++]);
free((*data)->append);
i = 0;
while ((*data)->herd[i])
	free((*data)->herd[i++]);
free((*data)->herd); 
*/

/* ************************************************************************** */