/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:22:41 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/29 16:59:44 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "../mlx_linux/mlx.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_print_error(2);
	check_file(argv);
	return (0);
}

	// t_data	data;

	// data.mlx_ptr = mlx_init();
	// if (!data.mlx_ptr)
	// 	return (ERROR);
	// data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "so_long");
	// if (!data.mlx_win)
	// {
	// 	free(data.mlx_win);
	// 	return (ERROR);
	// }
	// data.img.addr = "img/charizard.xpm";
	// data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.addr, &data.img.width, &data.img.height);
	// mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.mlx_img, 0, 0);
	// mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &keypress_handle, &data);
	// mlx_loop(data.mlx_ptr);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);