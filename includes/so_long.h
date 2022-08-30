/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:06:44 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/30 23:49:50 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include <X11/X.h>
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

# define WIDTH 1440
# define HEIGHT 720

# define ERROR 1
# define BUFFER_SIZE 1024

// # define RED_PIXEL 0xFF0000
// # define GREEN_PIXEL 0xFF00
// # define WHITE_PIXEL 0xFFFFFF

typedef	struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
}	t_img;

typedef	struct s_pos
{
	int	x;
	int	y;
}	t_pos;


typedef	struct s_map
{
	int		width;
	int		height;
	int		c;
	t_pos	player;
}	t_map;

typedef	struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*img;
	t_map	map;
}	t_data;



//--------------- PARSING ---------------//

int		check_file(char **argv);
char	**parse_map(char **argv, t_data *data);
int		check_map(char **map, t_data *data);

//--------------- MAIN ---------------//

int	main(int argc, char **argv);

//--------------- EVENTS ---------------//

int		no_event(void);
int		keypress_handle(int keysym, t_data *data);

//--------------- UTILS ---------------//

char	*get_next_line(int fd);
char	**get_all_map(int fd, char **argv);
int		ft_strchr(const char *str);
int		count_lines(char **argv);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_print_error();
int		ft_strncmp(char *s1, char *s2, int n);
int		is_valid(char *str, t_data *data);
void	ft_putstr(char *str);

#endif