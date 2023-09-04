/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:48:26 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/25 05:23:16 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_syntax_error(char *line, t_list **mini, char check)
{
	(void)mini;
	printf("minishell: syntax error near unexpected token `%c'\n", check);
	g_id.id = 1;
	if (*mini)
		ft_lstclear(mini);
	return (ft_strlen(line));
}

int	ft_check_pipe(t_list **mini, char *line, int i)
{
	t_list	*tmp;

	tmp = *mini;
	if (tmp && tmp->tok == PIPE)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		ft_lstclear(mini);
		g_id.id = 1;
		return (ft_strlen(line));
	}
	while (tmp)
	{
		if (tmp->tok == PIPE && tmp->next && tmp->next->tok == PIPE)
		{
			printf("minishell: syntax error near unexpected token `|'\n");
			ft_lstclear(mini);
			g_id.id = 1;
			return (ft_strlen(line));
		}
		tmp = tmp->next;
	}
	return (i);
}

void	ft_last_pipe(t_list **mini)
{
	if (*mini && ft_llast(*mini)->tok == PIPE)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		ft_lstclear(mini);
		g_id.id = 1;
	}
}
