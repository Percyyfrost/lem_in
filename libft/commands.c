/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:34:27 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/20 10:19:13 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		commands(char **arg, char **env)
{
	int i;
	int j;
	char *parth;
	char **tmp;

	j = 0;
	tmp = NULL;
	while (env[j])
		j++;
	if (!(tmp = (char **)malloc(sizeof(char) * (j + 1))))
		return (0);
	if (ft_strcmp(arg[0], "echo") == 0)
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (ft_strchr(arg[i], '>'))
				break ;
			ft_echo(arg[i++], env);
		}
		ft_putchar('\n');
		i--;
		return (0);
	}
	if (ft_strncmp(arg[0], "/bin/", 4) == 0)
		execve(arg[0], arg, NULL);
	if (ft_strcmp(arg[0], "setenv") == 0)
		tmp = ft_setenv(arg[1], env);
	if (ft_strcmp(arg[0], "env") == 0)
		ft_env(env);
	if ((parth = search_merge(arg[0])) != NULL)
		execve(parth, arg, NULL);
	return (0);
}
