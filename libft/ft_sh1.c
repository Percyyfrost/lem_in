/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:51:04 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/20 10:50:44 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int main(int ac, char **av, char **env)
{
	char *line;
	int pid;
	char **argv;

	while (ac == 1 && av[0])
	{
		ft_putstr("e4r18p4% ");
		if (!get_next_line(1, &line))
			break ;
		argv = ft_strsplit(line, ' ');
		if (ft_strcmp(argv[0], "exit") == 0)
			break ;
		if (ft_strcmp(argv[0], "cd") == 0)
			cd(argv[1], env);
		pid = fork();		
		if (pid == 0)
		{
			if (comp(argv))
			{
				redir(argv[3], argv, env);
				exit(0);
			}
			commands(argv, env);
			exit(0);
		}
		else if (pid < 0)
			ft_putstr("unable to create process\n");
		else
			wait(NULL);
	}
	return (0);
}
