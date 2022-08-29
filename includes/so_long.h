/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:06:44 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/29 17:00:25 by zel-kass         ###   ########.fr       */
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

typedef	struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}	t_data;



//--------------- PARSING ---------------//

int	check_file(char **argv);

//--------------- MAIN ---------------//

int	main(int argc, char **argv);

//--------------- EVENTS ---------------//

int		no_event(void);
int		keypress_handle(int keysym, t_data *data);

//--------------- UTILS ---------------//

char	**get_next_line(int fd);
int		ft_strchr(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_print_error(int error);
int		ft_strncmp(char *s1, char *s2, int n);

#endif