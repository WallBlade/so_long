/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:29:15 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/08 12:19:30 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_print_error(int error)
{
	if (error == 1)
		write(2, "Error\n", 6);
	else if (error == 2)
		write(2, "Wrong number of arguments\n", 26);
	else if (error == 3)
		write(2, "Invalid file/filename\n", 22);
	else if (error == 4)
		write(2, "Invalid map\n", 12);
	exit (EXIT_FAILURE);
}

int	is_valid(char *str, t_data *data, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			data->map.c += 1;
		if (str[i] == 'P')
		{
			data->p_pos.x = i;
			data->p_pos.y = c;
			data->map.p += 1;
		}
		if (str[i] == 'E')
			data->map.e += 1;
		if ((!is_surrounded(c, i, str[i], data)) || (!check_char("01CEP", str[i])))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
