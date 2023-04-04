/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:23:00 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/17 18:03:23 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectible(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	**map_cpy(t_data *data)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = malloc(sizeof(char *) * (data->map.height + 2));
	if (!cpy)
		return (NULL);
	while (data->map.tab[i])
	{
		cpy[i] = ft_strdup(data->map.tab[i]);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
