/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:07:08 by lacollar          #+#    #+#             */
/*   Updated: 2019/12/13 16:12:24 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		combine_buffer(char **line, char *buf, char *reste)
{
	if (index_nwl(buf) >= 0)
	{
		if (!(ft_strcpy(reste, checknl(buf))))
			return (-1);
		if (!(*line = strjoin_modified(*line, buf)))
			return (-1);
		return (1);
	}
	if (!(*line = strjoin_modified(*line, buf)))
		return (-1);
	buf[0] = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	reste[OPEN_MAX][BUFFER_SIZE + 1];
	int			return_read;
	int			res;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line || read(fd, buf, 0) < 0 ||
		fd > OPEN_MAX)
		return (-1);
	if (!(*line = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	**line = 0;
	if (!(*line = strjoin_modified(*line, reste[fd])))
		return (-1);
	if (index_nwl(reste[fd]) >= 0)
		return ((ft_strcpy(reste[fd], checknl(reste[fd]))) ? 1 : -1);
	while ((return_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[return_read] = 0;
		if ((res = combine_buffer(line, buf, reste[fd])) != 0)
			return (res);
	}
	reste[fd][0] = 0;
	return (0);
}
