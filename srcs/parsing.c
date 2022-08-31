/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:10:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/31 16:03:34 by zel-kass         ###   ########.fr       */
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
	data->map.width = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		if (!is_valid(map[i], data, i))
			return (ERROR);
		if ((ft_strlen(map[i]) - 1) != data->map.width)
			return (ERROR);
		i++;
	}
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