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

void	init_copy(t_data *data, t_path *path)
{
	path->map = data->map.tab;
	path->x = data->p_pos.x;
	path->y = data->p_pos.y;
}

int		is_flooded(t_path *path)
{
	int	i;
	int	j;

	i = 1;
	while (path->map[i])
	{
		j = 1;
		while (path->map[i][j])
		{
			if (path->map[i][j] == 'P')
			{
				if (path->map[i][j + 1] == '0' || path->map[i][j + 1] == 'C')
					return (0);
				else if (path->map[i][j - 1] == '0' || path->map[i][j - 1] == 'C')
					return (0);
				else if (path->map[i + 1][j] == '0' || path->map[i + 1][j] == 'C')
					return (0);
				else if (path->map[i - 1][j] == '0' || path->map[i - 1][j] == 'C')
					return (0);
			}
		}
	}
	return (1);
}

void	flood_fill(t_path *path)
{
	int	x;
	int	y;

	x = path->x;
	y = path->y;
	while (!is_flooded(path))
	{
		if (path->map[y][x + 1])
	}
}