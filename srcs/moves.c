/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:59:28 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/06 14:50:51 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->map.tab[x + 1] == '0')
	{
		data->map.tab[x] = '0';
		data->map.tab[x + 1] = 'P';
		data->count += 1;
	}
	return (0);
}

void	move_hooks(int keycode, t_data *data)
{
	if (keycode == XK_D)
		mlx_hook(data->mlx_win, KeyPress, KeyPressMask, move_right, &data);
}