/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:51:32 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/17 16:08:32 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_img(t_data *data)
{
	if (!data->walls.mlx_img)
		return (destroy_img(data), 0);
	else if (!data->player.mlx_img)
		return (destroy_img(data), 0);
	else if (!data->land.mlx_img)
		return (destroy_img(data), 0);
	else if (!data->pot.mlx_img)
		return (destroy_img(data), 0);
	else if (!data->exit.mlx_img)
		return (destroy_img(data), 0);
	return (1);
}

int	init_img(t_data *data)
{
	data->walls.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/walls.xpm", &data->walls.width, &data->walls.height);
	data->player.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/tanjiro.xpm", &data->player.width, &data->player.height);
	data->land.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/land.xpm", &data->land.width, &data->land.height);
	data->pot.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/pot.xpm", &data->pot.width, &data->pot.height);
	data->exit.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/exit.xpm", &data->exit.width, &data->exit.height);
	if (!check_img(data))
		return (ERROR);
	return (SUCCESS);
}

void	get_img_addr(char c, t_data *data, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->walls.mlx_img, y * 50, x * 50);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->land.mlx_img, y * 50, x * 50);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->player.mlx_img, y * 50, x * 50);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->pot.mlx_img, y * 50, x * 50);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->exit.mlx_img, y * 50, x * 50);
}

int	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			get_img_addr(data->map.tab[i][j], data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	destroy_img(t_data *data)
{
	if (data->walls.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->walls.mlx_img);
	if (data->player.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->player.mlx_img);
	if (data->land.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->land.mlx_img);
	if (data->pot.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->pot.mlx_img);
	if (data->exit.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->exit.mlx_img);
}
