/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:10:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/30 17:56:28 by zel-kass         ###   ########.fr       */
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

int	check_chars(char **map, t_data *data)
{
	int		i;
	int		j;
	char	*valid;

	i = 0;
	valid = "01CEP";
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (!is_valid(map[i][j], valid))
				return (ERROR);
			j++;
		}
		i++;
	}
}

char	**parse_map(char **argv, t_data *data)
{
	char	**map;
	int		fd;
	int 	i;

	i = 0;
	fd = check_file(argv);
	map = get_all_map(fd, argv);
	return (map);
}