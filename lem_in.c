/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:17:27 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/03 16:17:33 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	int fd;
	char *line;
	t_graph *farm;
	int i;
	int y, x, k = 0;
	char **tmp;	

	y = 0;
	if (ac != 2)
	{
		ft_putendl("insert map");
		return(0);
	}
	fd = open(av[1], O_RDONLY);
	tmp = (char**)malloc(sizeof(char*) * (4));
	while(get_next_line(fd, &line))
	{
		if (i == 0)
			farm = graph(ft_atoi(&line[0]) + 1);
		if (line[0] != '#')
		{
			while(line[k])
				k++;
			if(k >= 4)
			{
				tmp[y] = (char*)malloc(sizeof(char*) *(ft_strlen(tmp[y])));
				tmp[y] = line;
				y++;
			}
			if(ft_strchr(line, '-'))
				addedge(farm, ft_atoi(&line[0]), ft_atoi(&line[2]));
		}
		i++;
		k = 0;
	}
	get_distance(tmp);
	print_graph(farm);
	return(0);
}
