/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:09:00 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/21 07:12:54 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_echo(char *line, char **env)
{
	int i, j;
	int k;
	char *name;

	i = 0;
	j = 0;
	k = 1;
	name = (char *)malloc(sizeof(char) * (ft_strlen(line)));
	if (ft_strchr(line, '$'))
	{ 
		while (line[k])
			name[j++] = line[k++];
		name[j] = '\0';
		while (env[i])
		{
			if (ft_strstr(env[i], name) != 0)
			  {
			  while(env[i][j] != '=')
			  j++;
			  j++;
			  while (env[i][j])
			  write(1, &env[i][j++], 1);
			  }
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	if (ft_strchr(line, '"'))
	{
		while((int)(ft_strlen(line) - 1) != i)
			ft_putchar(line[i++]);
	}
	else
	{
		if (ft_strcmp(line, "<") == 0)
			return (0) ;
		ft_putstr(line);
	}
	ft_putchar(' ');
	return (0);
}
