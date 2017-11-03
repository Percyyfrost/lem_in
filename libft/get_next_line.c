/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:43:29 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/02 22:37:13 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_malloc_again(char **cache)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*cache));
	if (!tmp)
		return (0);
	ft_strcpy(tmp, *cache);
	*cache = NULL;
	*cache = ft_strnew(ft_strlen(tmp) + BUFF_SIZE);
	if(!*cache) 
		return (0);
	ft_strcpy(*cache, tmp);
	return (1);
}

int		get_line(int j, char **cache, char **line)
{
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (j != 0 || ft_strlen((*cache)) != 0)
	{
		while ((*cache)[i] != '\n')
		{
			(*line)[i] = (*cache)[i];
			i++;
		}
		(*line)[i++] = '\0';
		if ((*cache)[0] == '\n')
		{
			while ((*cache)[i])
				(*cache)[y++] = (*cache)[i++];
			(*cache)[y] = '\0';
			return (2);
		}
		while ((*cache)[i])
			(*cache)[y++] = (*cache)[i++];
		(*cache)[y] = '\0';
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			j;
	static char	*cache;

	if (fd < 0 || (!cache && !(cache = ft_strnew(BUFF_SIZE))))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((j = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (!(ft_malloc_again(&cache)))
			return (-1);
		ft_strncat(cache, *line, BUFF_SIZE);
		if (ft_memchr(*line, '\n', BUFF_SIZE))
			break ;
	}
	if ((get_line(j, &cache, &(*line))) == 2)
		return (1);
	if (ft_memcmp((*line), cache, ft_strlen(*line)) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return (0);
	}
	return (1);
}
