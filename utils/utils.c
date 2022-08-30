/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:29:15 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/30 23:57:22 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static long	ft_numlen(long nb)
{
	long	size;

	size = 0;
	if (nb == 0)
		size++;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	long	nb;
	long	len;
	char	*str;

	nb = nbr;
	len = ft_numlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[--len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
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

int	is_valid(char *str, t_data *data, int i)
{
	int	i;
	int	j;
	char *valid;

	i = 0;
	valid = "01CEP";
	printf("width = %d\tlen = %d\n", data->map.width, ft_strlen(str));
	if ((ft_strlen(str) - 1) != data->map.width)
		return (1);
	while (str[i] && str[i] != '\n')
	{
		j = 0;
		while (valid[j] && valid[j] != str[i])
			j++;
		if (valid[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}