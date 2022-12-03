NAME = fractol

MLX = -framework OpenGL -framework AppKit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS := colors_and_stuff.c fractals.c hooks.c simple_functions.c main.c

OBJS = $(SRCS:%.c=%.o)

HEADERS = ./fractol.h \
          ./minilibx/mlx.h		

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) libmlx.a
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS) -L. -lmlx

libmlx.a:
	$(MAKE) -C ./minilibx
	mv ./minilibx/libmlx.a .

$(%.o): $(%.c)
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re