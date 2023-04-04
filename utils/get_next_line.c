/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:28:24 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/17 18:03:41 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_clean(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	j = 0;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (stash[i] && buf[j])
		buf[j++] = stash[++i];
	buf[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			res;
	char		*line;
	char		*stash;
	static char	buf[BUFFER_SIZE + 1];

	res = BUFFER_SIZE;
	stash = NULL;
	stash = ft_strjoin(stash, buf);
	while (res == BUFFER_SIZE && !ft_strchr(buf))
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
			return (free(stash), NULL);
		buf[res] = '\0';
		if (res == 0 && !stash[0])
			return (free(stash), NULL);
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (NULL);
	}
	line = ft_clean(stash, buf);
	return (free(stash), line);
}

char	**get_all_map(int fd, char **argv, t_data *data)
{
	int		i;
	int		size;
	char	**map;

	i = 0;
	size = count_lines(argv);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	data->map.height = size - 1;
	while (size-- > 0)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}
