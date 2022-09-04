/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:09:25 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/04 11:40:35 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_event(void)
{
	return (0);
}

int	keypress_handle(int keysym, t_data *data)
{
	if (data->mlx_win && keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	return (0);
}
