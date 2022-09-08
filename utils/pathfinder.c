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
	j = 1;
}

void	flood_fill(t_path *path)
{
	
}