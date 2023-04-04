/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:28:18 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/17 18:06:18 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ERROR);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (ERROR);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*dest;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	ft_strchr(const char *str)
{
	int		i;

	if (!str)
		return (ERROR);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int	count_lines(char **argv)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	count = 1;
	while (count)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (count - 1);
		count++;
		free(line);
	}
	close(fd);
	return (0);
}
