/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:10:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/04 11:40:19 by zel-kass         ###   ########.fr       */
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

int	check_map(char **map, t_data *data)
{
	int		i;

	i = 0;
	data->map.width = ft_strlen(map[i]);
	while (map[i])
	{
		if (!is_valid(map[i], data, i))
			return (ERROR);
		if ((ft_strlen(map[i])) != data->map.width)
			return (ERROR);
		i++;
	}
	if (data->map.c < 1 || data->map.p != 1 || data->map.e != 1)
		return (ERROR);
	return (SUCCESS);
}

char	**parse_map(char **argv, t_data *data)
{
	char	**map;
	int		fd;

	fd = check_file(argv);
	map = get_all_map(fd, argv, data);
	if (!check_map(map, data))
	{
		ft_freetab(map, data->map.height);
		ft_print_error(4);
	}
	return (map);
}

void	global_init(char **argv)
{
	t_data	data;
	char	**map;

	ft_bzero(&data, sizeof(data));
		data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	map = parse_map(argv, &data);
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.map.width * 50, data.map.height * 50, "so_long");
	if (!data.mlx_win)
		return (free(data.mlx_win));
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &keypress_handle, &data);
	display_map(map, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}