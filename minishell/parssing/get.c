/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:38:01 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/29 02:09:30 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//get text -----------------------------------------------------------

char	*between_quot(char *line, char check, int start)
{
	int	i;

	i = start;
	while (line[i] != check && line[i])
		i++;
	if (line[i] == check)
		return (ft_substr(line, start, i - start));
	return (0);
}

int	get_text(char *line, t_var var, t_list **m, t_env *env)
{
	char	*text;
	t_cmd	*cmd;
	int		i;

	text = between_quot(line, var.check, var.i);
	i = var.i - 2;
	if (text)
	{
		if (i >= 0 && !is_space(line[i]) && !is_sprt(line[i]))
		{
			cmd = ft_clast(ft_llast(*m)->cmd);
			cmd->content = ft_strjoin(ft_clast(ft_llast(*m)->cmd)->content, \
			ft_d(text, env, var.check));
		}
		else if (!ft_llast(*m) || ft_llast(*m)->tok == PIPE \
		|| is_redi(m))
			ft_lstadd(m, ft_lnew(CMD, ft_cnew(ft_d(text, env, var.check))));
		else
			ft_cmdadd(&ft_llast(*m)->cmd, ft_cnew(ft_d(text, env, var.check)));
		return (var.i + ft_strlen(text) + 1);
	}
	else
		return (ft_syntax_error(line, m, var.check));
	return (ft_strlen(text) + var.i);
}

//get file -----------------------------------------------------------

void	ft_redi(char *line, int i, t_list **mini, char check)
{
	if (i > 1 && line[i - 1] == check && line[i - 2] == check)
	{
		if (check == '<')
			ft_lstadd(mini, ft_lnew(HERD, ft_cnew(0)));
		else
			ft_lstadd(mini, ft_lnew(APPEND, ft_cnew(0)));
	}
	else
	{
		if (check == '<')
			ft_lstadd(mini, ft_lnew(RED_IN, ft_cnew(0)));
		else
			ft_lstadd(mini, ft_lnew(RED_OUT, ft_cnew(0)));
	}
}

int	get_cont(char *in, t_list **mini, t_env *envlst, t_var var)
{
	int		i;
	t_cmd	*cmd;

	i = var.i;
	while (!is_special(in[i]) && !is_space(in[i]) && in[i])
		i++;
	cmd = ft_llast(*mini)->cmd;
	if (ft_llast(*mini)->tok != HERD)
		cmd->content = ft_d(ft_substr(in, var.i, i - var.i), envlst, var.check);
	else
		cmd->content = ft_substr(in, var.i, i - var.i);
	return (i);
}

int	get_file(char *in, t_var var, t_list **mini, t_env *envlst)
{
	int		i;

	i = var.i;
	ft_redi(in, i, mini, var.check);
	while (is_space(in[i]) && in[i])
		i++;
	if (in[i] && !is_special(in[i]))
	{
		var.i = i;
		i = get_cont(in, mini, envlst, var);
	}
	else
	{
		var.check = in[i];
		var.i = i + 1;
		if (is_qt(in[i]))
			i = get_text(in, var, mini, envlst);
		else
			return (ft_syntax_error(in, mini, var.check));
	}
	return (i);
}
