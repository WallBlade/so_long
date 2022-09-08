/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:59:28 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/08 13:53:48 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->p_pos.x;
	y = data->p_pos.y;
	if (data->map.tab[y][x + 1] == '0' || data->map.tab[y][x + 1] == 'C')
	{
		if (data->map.tab[y][x + 1] == 'C')
			data->map.c--;
		data->map.tab[y][x] = '0';
		data->map.tab[y][x + 1] = 'P';
		data->count += 1;
		data->p_pos.x++;
		ft_putnbr(data->count);
		ft_putstr("\n");
	}
	if (data->map.tab[y][x + 1] == 'E' && data->map.c == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		ft_putstr("GG's\n");
	}
	return (0);
}

int	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->p_pos.x;
	y = data->p_pos.y;
	if (data->map.tab[y][x - 1] == '0' || data->map.tab[y][x - 1] == 'C')
	{
		if (data->map.tab[y][x - 1] == 'C')
			data->map.c--;
		data->map.tab[y][x] = '0';
		data->map.tab[y][x - 1] = 'P';
		data->count += 1;
		data->p_pos.x--;
		ft_putnbr(data->count);
		ft_putstr("\n");
	}
	if (data->map.tab[y][x - 1] == 'E' && data->map.c == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		ft_putstr("GG's\n");
	}
	return (0);
}

int	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->p_pos.x;
	y = data->p_pos.y;
	if (data->map.tab[y - 1][x] == '0' || data->map.tab[y - 1][x] == 'C')
	{
		if (data->map.tab[y - 1][x] == 'C')
			data->map.c--;
		data->map.tab[y][x] = '0';
		data->map.tab[y - 1][x] = 'P';
		data->count += 1;
		data->p_pos.y--;
		ft_putnbr(data->count);
		ft_putstr("\n");
	}
	if (data->map.tab[y - 1][x] == 'E' && data->map.c == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		ft_putstr("GG's\n");
	}
	return (0);
}

int	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->p_pos.x;
	y = data->p_pos.y;
	if (data->map.tab[y + 1][x] == '0' || data->map.tab[y + 1][x] == 'C')
	{
		if (data->map.tab[y + 1][x] == 'C')
			data->map.c--;
		data->map.tab[y][x] = '0';
		data->map.tab[y + 1][x] = 'P';
		data->count += 1;
		data->p_pos.y++;
		ft_putnbr(data->count);
		ft_putstr("\n");
	}
	if (data->map.tab[y + 1][x] == 'E' && data->map.c == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		ft_putstr("GG's\n");
	}
	return (0);
}

int	keypress_handle(int keycode, t_data *data)
{
	if (data->mlx_win && keycode == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	if (keycode == 100)
		move_right(data);
	if (keycode == 97)
		move_left(data);
	if (keycode == 119)
		move_up(data);
	if (keycode == 115)
		move_down(data);
	return (0);
}
