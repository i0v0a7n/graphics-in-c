NAME = cub3D

MLX = -framework OpenGL -framework AppKit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS		:=  advanced_drawers.c \
			casthelpers.c \
			draw.c \
			fundamental.c \
			mainhelpers.c \
			map_checker.c \
			map_parser.c \
			movements.c \
			parse_file.c \
			parser.c \
			read_as_line.c \
			screen_shooter.c \
			set_floor_and_ceiling.c \
			set_sides.c \
			set_texture_params.c \
			simple_drawers.c \
			sort.c \
			xcaster.c \
			ycaster.c \
			main.c

OBJS = $(SRCS:%.c=%.o)

HEADERS =	./cub.h \
			./minilibx/mlx.h \
			./libft/libft.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) libft.a libmlx.a
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS) -L. -lft -lmlx

libmlx.a:
	$(MAKE) -C ./minilibx
	mv ./minilibx/libmlx.a .

libft.a:
	$(MAKE) -C ./libft
	mv ./libft/libft.a .

$(%.o): $(%.c)
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libft.a libmlx.a

re: clean all

.PHONY: all clean fclean re