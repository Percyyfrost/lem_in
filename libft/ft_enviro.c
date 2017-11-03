/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enviro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:08:33 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/19 07:10:27 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	(char *set, char **env)
{
	char **tmp;

	if (ft_strcmp(arg[0], "setenv") == 0)
		ft_setenv(set, env) = tmp;
	if (ft_strstr(arg[0], "env"))
		ft_env(tmp);
}
