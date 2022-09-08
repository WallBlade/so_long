/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:10:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/08 14:37:43 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char **argv)
{
	int		fd;
	int		len;
	char	*valid;

	len = ft_strlen(argv[1]) - 4;
	valid = ".ber";
	if (ft_strncmp(&argv[1][len], valid, 4) != 0)
		ft_print_error(3);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_print_error(3);
	return (fd);
}

int	check_map(t_data *data)
{
	int		i;

	i = 0;
	data->map.width = ft_strlen(data->map.tab[i]) - 1;
	while (data->map.tab[i])
	{
		if (!is_valid(data->map.tab[i], data, i))
			return (ERROR);
		if ((ft_strlen(data->map.tab[i]) - 1) != data->map.width)
			return (ERROR);
		i++;
	}
	if (data->map.c < 1 || data->map.p != 1 || data->map.e != 1)
		return (ERROR);
	return (SUCCESS);
}

void	parse_map(char **argv, t_data *data)
{
	int		fd;

	fd = check_file(argv);
	data->map.tab = get_all_map(fd, argv, data);
	if (!check_map(data))
	{
		ft_freetab(data->map.tab, data->map.height);
		ft_print_error(4);
	}
}

void	global_init(char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	parse_map(argv, &data);
	data.mlx_win = mlx_new_window(data.mlx_ptr, (data.map.width + 1) * 50,
			(data.map.height + 1) * 50, "so_long");
	if (!data.mlx_win)
		return (free(data.mlx_win));
	init_img(&data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &keypress_handle, &data);
	mlx_hook(data.mlx_win, 17, 1L << 5, mouse_click, &data);
	mlx_loop_hook(data.mlx_ptr, display_map, &data);
	mlx_loop(data.mlx_ptr);
	destroy_img(&data);
	ft_freetab(data.map.tab, data.map.height);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
