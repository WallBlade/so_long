/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:18:01 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/08 16:21:59 by zel-kass         ###   ########.fr       */
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

int	is_flooded(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
					return (0);
				if (map[y][x - 1] == '0' || map[y][x + 1] == 'C')
					return (0);
				if (map[y + 1][x] == '0' || map[y][x + 1] == 'C')
					return (0);
				if (map[y - 1][x] == '0' || map[y][x + 1] == 'C')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	fill(char **map, int y, int x)
{
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		map[y][x + 1] = 'P';
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		map[y][x - 1] = 'P';
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		map[y + 1][x] = 'P';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		map[y - 1][x] = 'P';
}

void	flood(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				fill(map, y, x);
			x++;
		}
		y++;
	}
}

int	valid_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i][j + 1] == 'P')
					return (1);
				if (map[i][j - 1] == 'P')
					return (1);
				if (map[i + 1][j] == 'P')
					return (1);
				if (map[i - 1][j] == 'P')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(t_data *data)
{
	char	**map;

	map = data->map.tab;
	while (!is_flooded(map))
		flood(map);
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	if (valid_path(map) && !check_collectible(map))
		printf("m3lem\n");
}
