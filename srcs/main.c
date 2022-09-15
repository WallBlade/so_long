/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:22:41 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/15 17:16:30 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_click(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_print_error(2);
	global_init(argv);
	return (0);
}
