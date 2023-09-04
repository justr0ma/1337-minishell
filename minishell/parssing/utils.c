/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:29:19 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/20 05:57:34 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_sprt(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	is_qt(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

int	is_redi(t_list **mini)
{
	int		i;
	char	*tmp;

	i = ft_llast(*mini)->tok;
	if (ft_llast(*mini)->cmd != 0)
		tmp = ft_llast(*mini)->cmd->content;
	else
		tmp = 0;
	if (tmp && (i == RED_IN || i == RED_OUT || i == HERD || i == APPEND))
		return (1);
	return (0);
}

int	is_special(char c)
{
	if (is_sprt(c) || is_qt(c))
		return (1);
	return (0);
}
