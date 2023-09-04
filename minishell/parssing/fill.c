/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/09/03 23:16:29 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	add_cmd(char *in, t_list **mini, int start, t_env *envlst)
{
	int		i;
	int		k;
	char	*tmp;
	char	*tmp2;

	i = start;
	k = start - 1;
	while (!is_space(in[i]) && !is_sprt(in[i]) && !is_qt(in[i]) && in[i])
		i++;
	tmp = ft_substr(in, start, i - start);
	if (k >= 0 && is_qt(in[k]))
	{
		tmp2 = ft_join(ft_clast(ft_llast(*mini)->cmd)->content, \
		ft_d(tmp, envlst, 0));
		ft_clast(ft_llast(*mini)->cmd)->content = tmp2;
	}
	else if (ft_llast(*mini) != 0 && ft_llast(*mini)->tok == CMD)
		ft_cmdadd(&ft_llast(*mini)->cmd, ft_cnew(ft_d(tmp, envlst, 0)));
	else
		ft_lstadd(mini, ft_lnew(CMD, ft_cnew(ft_d(tmp, envlst, 0))));
	return (i);
}

void	is_done(t_list **mini, t_data **data)
{
	if (*mini)
		ft_takespace(mini, data);
	if (*mini)
		ft_datafill(mini, data);
}

void	parsser(char *line, t_data **data, t_env *envlst, t_list **mini)
{
	int		i;

	i = 0;
	*mini = 0;
	*data = 0;
	if (line[i] == '\0')
	{
		free (line);
		return ;
	}
	while (line[i])
	{
		while (is_space(line[i]))
			i++;
		if (line[i] == '\0')
			break ;
		if ((is_sprt(line[i]) || is_qt(line[i])))
			i = get_cmd(line, i, mini, envlst);
		else
			i = add_cmd(line, mini, i, envlst);
		i = ft_check_pipe(mini, line, i);
	}
	ft_last_pipe(mini);
	is_done(mini, data);
	free(line);
}

//get command (main function) ----------------------------------------
int	get_cmd(char *line, int start, t_list **mini, t_env *envlst)
{
	t_var	var;

	var.check = line[start];
	var.i = start + 1;
	if (var.check == '|')
	{
		ft_lstadd(mini, ft_lnew(PIPE, ft_cnew(ft_strdup("|"))));
		start++;
	}
	else if (is_qt(var.check))
		start = get_text(line, var, mini, envlst);
	else if (var.check == '<' || var.check == '>')
	{
		if (line[start + 1] == var.check)
		{
			var.i = start + 2;
			start = get_file(line, var, mini, envlst);
		}
		else
		{
			var.i = start + 1;
			start = get_file(line, var, mini, envlst);
		}
	}
	return (start);
}
