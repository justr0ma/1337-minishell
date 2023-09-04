/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:29:49 by halaqoh           #+#    #+#             */
/*   Updated: 2022/08/16 22:52:12 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_envi(t_env	*envm)
{
	while (envm->next)
	{
		printf("%s=%s\n", envm->key, envm->value);
		envm = envm->next;
	}
	printf("%s=%s\n", envm->key, envm->value);
	return (1);
}
