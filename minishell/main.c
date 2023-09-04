/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:32 by abouhmad          #+#    #+#             */
/*   Updated: 2022/09/03 23:35:15 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//just exection signal ---------------------------------------------------------
void	handle_sigint(int sig)
{	
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_id.id = 1;
	}
}

void	fill_env(t_env **envlst, t_env **exp, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			if (env[i][j] == '=')
			{
				ft_envadd_back(envlst, ft_enew(ft_substr(\
				env[i], 0, j), ft_strdup(env[i] + j + 1)));
				ft_envadd_back(exp, ft_enew(ft_substr(\
				env[i], 0, j), ft_strdup(env[i] + j + 1)));
				break ;
			}
			j++;
		}
		i++;
	}
	(*envlst)->statexit = 0;
}

void	ft_cmd_done(t_data *data, t_env **envlst, t_list *mini, t_env **exp)
{
	if (data)
		ft_execprocess(data, envlst, exp);
	if (mini)
		ft_lstclear(&mini);
	if (data)
		ft_dataclear(&data);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*envlst;
	t_env	*exp;
	t_data	*data;
	t_list	*mini;

	(void) ac;
	(void) av;
	fill_env(&envlst, &exp, env);
	g_id.id = 0;
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		line = readline("\033[0;36m\x1b[1m➡️  mini \033[0m ");
		if (line == 0)
			exit (g_id.id);
		if (line[0] != '\0')
			add_history(line);
		envlst->statexit = g_id.id;
		parsser(line, &data, envlst, &mini);
		ft_cmd_done(data, &envlst, mini, &exp);
	}
	return (0);
}
