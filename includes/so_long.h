/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:06:44 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/15 17:28:09 by zel-kass         ###   ########.fr       */
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

# define ERROR 0
# define SUCCESS 1
# define BUFFER_SIZE 1024

typedef	struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef	struct s_map
{
	char	**tab;
	int		width;
	int		height;
	int		c;
	int		p;
	int		e;
}	t_map;

typedef	struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	char	*path;
}	t_img;


typedef	struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		count;
	t_img	walls;
	t_img	player;
	t_img	pot;
	t_img	land;
	t_img	exit;
	t_map	map;
	t_pos	p_pos;
}	t_data;

//--------------- PARSING ---------------//

int		check_file(char **argv);
int		check_map(t_data *data);
void	parse_map(char **argv, t_data *data);
void	global_init(char **argv);

//--------------- MAIN ---------------//

int		main(int argc, char **argv);

//--------------- EVENTS ---------------//

int		mouse_click(t_data *data);
int		keypress_handle(int keycode, t_data *data);
void	all_hooks(t_data *data);
void	move_hooks(int keycode, t_data *data);

//--------------- UTILS ---------------//

char	*get_next_line(int fd);
char	**get_all_map(int fd, char **argv, t_data *data);
int		ft_strchr(const char *str);
int		count_lines(char **argv);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_print_error(int error);
int		ft_strncmp(char *s1, char *s2, int n);
int		is_valid(char *str, t_data *data, int c);
char	**ft_freetab(char **s, int n);
void	ft_bzero(void *s, size_t n);
int		check_char(char *valid, char c);
void	ft_putstr(char *str);
int		is_surrounded(int c, int i, char k, t_data *data);
int		display_map(t_data *data);
void	init_img(t_data *data);
void	destroy_img(t_data *data);
void	ft_putnbr(int nb);
int		flood_fill(t_data *data);
int		check_collectible(char **map);
char	**map_cpy(t_data *data);

#endif