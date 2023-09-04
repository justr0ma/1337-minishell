/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:26 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/05 15:45:03 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_list	*ft_lnew(int tok, t_cmd *cmd)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->tok = tok;
	p->cmd = cmd;
	p -> next = 0;
	return (p);
}

t_cmd	*ft_cnew(char *content)
{
	t_cmd	*p;

	p = malloc (sizeof(t_cmd));
	if (!p)
		return (0);
	p->content = content;
	p->next = 0;
	return (p);
}

t_env	*ft_enew(char *key, char *value)
{
	t_env	*p;

	p = malloc (sizeof(t_env));
	if (!p)
		return (0);
	p->key = key;
	p->value = value;
	p->next = 0;
	return (p);
}

t_data	*ft_datanew(void)
{
	t_data	*p;
	int		i;

	p = malloc (sizeof(t_data));
	if (!p)
		exit(EXIT_FAILURE);
	p->cmd = 0;
	p->inf = 0;
	p->outf = 0;
	p->append = 0;
	p->herd = 0;
	p->ct = malloc(sizeof(int) * 5);
	if (!p->ct)
		exit(EXIT_FAILURE);
	p->in = 0;
	p->out = 0;
	i = 0;
	while (i < 5)
		p->ct[i++] = 1;
	p->error = 0;
	p->next = 0;
	return (p);
}
