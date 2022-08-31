/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:56:45 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/31 19:03:14 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	**ft_freetab(char **s, int n)
{
	while (n >= 0)
	{
		free(s[n]);
		n--;
	}
	free(s);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = '\0';
}

int		check_char(char *valid, char c)
{
	int	i;

	i = 0;
	while (valid[i] && valid[i] != c)
		i++;
	if (valid[i] == '\0')
		return (ERROR);
	return (SUCCESS);
}

int		is_surrounded(int c, int i, char k, t_data *data)
{
	if (c == 0 || c == data->map.height
		|| i == 0 || i == data->map.width)
		if (k != '1')
			return (ERROR);
	return (SUCCESS);
}