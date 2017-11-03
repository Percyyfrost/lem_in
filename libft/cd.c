/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:04:01 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/08 09:27:58 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cd(char *dir, char **env)
{
	int i;
	char *home;

	i = 0;
	home = ft_strchr(env[16], '/');
	if (access(dir, X_OK) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(dir);
	}

	if (dir == NULL || ft_strcmp(dir, "~") == 0)
		chdir(home);
	else
		chdir(dir);
}
