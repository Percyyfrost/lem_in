/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:28:36 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/18 15:52:25 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	redir(char *name, char **str, char **env)
{
	int in;
	in = open("in", O_RDONLY);
	dup2(in, 0);
	close(in);
	int  out;
	out = open(name, O_WRONLY | O_CREAT,  S_IRUSR | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
	dup2(out, 1);
	close(out);
	commands(str, env);
}
