SRC		=	srcs/main.c srcs/events.c utils/get_next_line.c utils/get_next_line_utils.c utils/utils.c \
			srcs/parsing.c utils/utils_1.c srcs/display.c\

OBJ		= $(SRC:.c=.o)

CC		=		cc
RM		=		rm -rf
CFLAGS	=		-Wall -Werror -Wextra -I./includes

NAME	=		so_long

all: 			$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I./includes -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):		$(OBJ)
					$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
					$(RM) $(OBJ)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re