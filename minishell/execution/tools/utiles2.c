/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:57:33 by halaqoh           #+#    #+#             */
/*   Updated: 2022/09/03 23:45:25 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_strchrp(char *s)
{
	int		i;
	char	*c;

	c = "PATH";
	i = 0;
	while (i < 4)
	{
		if (s[i] != c[i])
			return (0);
		i++;
	}
	return (1);
}

char	*patho(t_env	*envp, char *args)
{
	int		i;
	char	**penv;
	char	*roma;

	i = 0;
	while (!ft_strchrp(envp->key))
		envp = envp->next;
	penv = ft_split(envp->value, ':');
	i = 0;
	while (penv[i])
	{
		roma = ft_strjoin(penv[i], "/");
		if (!access(ft_strjoin(roma, args), F_OK))
		{
			return (ft_strjoin(roma, args));
		}
		i++;
	}
	return (args);
}

char	**ft_exenv(t_env *envm)
{
	int		i;
	int		j;
	char	**envs;
	t_env	*tmpenv;

	i = 0;
	tmpenv = envm;
	while (envm)
	{
		i++;
		envm = envm->next;
	}
	envs = (char **)malloc((i + 1) * sizeof(char *));
	envm = tmpenv;
	j = 0;
	while (j < i)
	{
		envs[j] = ft_strjoin(ft_strjoin(envm->key, "="), envm->value);
		envm = envm->next;
		j++;
	}
	envs[j] = 0;
	return (envs);
}

int	ft_normexec(t_env **envm, t_env **exp, t_data *p, t_pip *pip)
{
	if (check_builtins(envm, exp, p) != 0)
	{
		ft_stand_inout(pip);
		ft_pipclear(&pip);
		return (1);
	}
	else
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		g_id.id = -4;
		pip->pid[0] = fork();
		if (pip->pid[0] == 0)
			ft_execmd(*envm, p, ft_exenv(*envm));
	}
	return (0);
}
