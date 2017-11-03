/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:20:28 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/10 14:14:25 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_setenv(char *str, char **env)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (str == NULL)
		return (NULL);
	if (ft_strchr(str, '='))
	{
	while (env[i])
		i++;
	if(!(tmp = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (env[i])
	{
		tmp[i] = env[i];
		i++;
	}
	tmp[i] = str;
	}
	else
	{
		ft_putstr("setenv: ");
		ft_putstr(str);
		ft_putendl(": No such file or directory");
		return(0);
	}
	return (tmp);
}
