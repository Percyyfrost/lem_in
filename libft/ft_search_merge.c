/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:37:58 by vnxele            #+#    #+#             */
/*   Updated: 2017/08/20 11:20:49 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>

char	*search_merge(char *cmd)
{
	DIR				*dir;
	struct dirent	*file;
	char			*bin;
	char			*parth;
	char			filename[50];

	bin = "/bin/";
	dir = opendir("/bin/");
	parth = NULL;
	while ((file = readdir(dir)) != NULL)
	{
		ft_strncpy(filename, file->d_name, 49);
		if (ft_strcmp(cmd, filename) == 0)
			parth = ft_strjoin(bin, cmd);
	}
	if (parth == NULL)
		return (NULL);
	closedir(dir);
	return (parth);
}
