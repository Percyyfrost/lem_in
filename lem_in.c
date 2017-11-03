/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:17:27 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/03 05:03:48 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	int fd;
	char *line;
	t_graph *farm;
	int i;

	if (ac != 2)
	{
		ft_putendl("insert map");
		return(0);
	}
	fd = open(av[1], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		if (i == 0)
			farm = graph(ft_atoi(&line[0]) + 1);
		if (line[0] != '#')
		{
			if(ft_strchr(line, '-'))
				addedge(farm, ft_atoi(&line[0]), ft_atoi(&line[2]));
		}
		i++;
	}
	print_graph(farm);
	return(0);
}
