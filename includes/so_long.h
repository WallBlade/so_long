/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:06:44 by zel-kass          #+#    #+#             */
/*   Updated: 2022/09/01 15:48:15 by zel-kass         ###   ########.fr       */
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

# define ERROR 0
# define SUCCESS 1
# define BUFFER_SIZE 1024

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
	int		collectible;
	int		p;
	int		e;
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

#endif