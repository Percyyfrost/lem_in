/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 11:58:47 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/03 15:01:46 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsetenv(char *unset,char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		if (i == 5)
			i++;
		ft_putendl(env[i++]);
	}
}

int		main(int ac, char **av, char **env)
{
	ft_unsetenv(av[1], env);
	return (0);
}
