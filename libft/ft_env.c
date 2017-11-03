/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:36:12 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/20 10:15:59 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		ft_putendl(arr[i++]);
}

char	**ft_env(char **env)
{
	int i, j, len;
	char **tmp;

	i = 0;
	j = 0;
	while(env[j])
		j++;
	if (!(tmp = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	while (env[i])
	{
		len = ft_strlen(env[i]);
		if (!(tmp[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strcpy(tmp[i],env[i]);
		i++;
		//if (ft_strstr(env[i], "OLDPWD") != 0)
		//{
		//	len = ft_strlen(env[i]);
		//	tmp = (char *)malloc(sizeof(char) * (len + 1));
		//	ft_strcpy(tmp, env[i]);
		//}
	}
	char *name = "RIGOROUS";
	if (name != 0)
	{		
		ft_strcpy(tmp[i + 1],  name);
	}
	return (tmp);
}

//void	ft_setenv(char *name, char **env, int c)
//{
//
//}


