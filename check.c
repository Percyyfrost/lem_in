/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:24:30 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/11 12:37:39 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

int		is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int		nbr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return(0);
}

void	errors(int err)
{
	if (err == 1)
		ft_putendl("ant count invalid");
	if (err == 2)
		ft_putendl("invalid comment format");
	if (err == 3)
		ft_putendl("Missing start coordinates");
	if (err == 4)
		ft_putendl("Missing end coordinates");
}

int		check()
{
	int		fd;
	char	*line;
	int		i;
	int		s;
	int		e;

	i = 0;
	fd = open("map.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!i)
		{
			if (nbr(line))
				return(1);
			i++;
		}
		if (line[0] == '#' && line[1] != '#')
			return (2);
		if (!ft_strcmp(line, "##start"))
			s = 1;
		if (!ft_strcmp(line, "##end"))
			e = 1;
	}
	if (!s)
		return (3);
	if (!e)
		return (4);
	return(0);
}

int		main()
{
	int i;

	i = check();
	if (i)
		errors(i);
	else
		ft_putendl("okay");
	return(0);
}
