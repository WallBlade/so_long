/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:28:24 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/29 17:01:34 by zel-kass         ###   ########.fr       */
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
	if (stash[i] == '\n')
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
		buf[j++] = stash[i++];
	buf[j] = '\0';
	return (line);
}

char	**get_next_line(int fd)
{
	int			i;
	int			res;
	char		*line;
	char		*stash;
	static char	buf[BUFFER_SIZE + 1];

	res = BUFFER_SIZE;
	stash = NULL;
	i = 0;
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
	}
	line[i] = ft_clean(stash, buf);
	i++;
	if (res > 0)
		get_next_line(fd);
	return (free(stash), line);
}
