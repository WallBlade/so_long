/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:51:32 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/02 19:19:13 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img_addr(char c, t_data *data, int x, int y)
{
	void	*img;
	char	*addr;
	int		width;
	int		height;

	addr = NULL;
	if (c == '1')
		addr = "img/walls.xpm";
	else if (c == '0')
		addr = "img/land.xpm";
	else if (c == 'P')
		addr = "img/tanjiro.xpm";
	else if (c == 'C')
		addr = "img/collectible.xpm";
	else if (c == 'E')
		addr = "img/collectible.xpm";
	img = mlx_xpm_file_to_image(data->mlx_ptr, addr, &width, &height);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, y * 50, x * 50);
	mlx_destroy_image(data->mlx_ptr, img);
}

void	display_map(char **map, t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			get_img_addr(map[i][j], data, i, j);
			j++;
		}
		i++;
	}
}