/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrey <sfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:44:47 by sfrey             #+#    #+#             */
/*   Updated: 2021/05/07 16:56:59 by sfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <string.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		w_width;
	int		w_height;
}				t_win;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		line_l;
	int		height;
	int		bpp;
	int		en;
}				t_img;

typedef struct s_plr
{
	double	x;
	double	y;
	double	xorigin;
	double	yorigin;
	double	movespeed;
	double	dir;
	double	start;
	double	end;
}				t_plr;

typedef struct s_pair
{
	t_img	img;
	t_img	texture;
}				t_pair;

typedef struct s_sprite
{
	double	x;
	double	y;
	double	distance;
	t_img	texture;
}				t_sprite;

typedef struct s_inputs
{
	int	rightturn;
	int	leftturn;
	int	movebackward;
	int	moveforward;
	int	moveleft;
	int	moveright;
}				t_inputs;

typedef struct s_all
{
	t_win		win;
	t_plr		plr;
	t_inputs	inputs;
	t_img		minimap;
	t_img		maprays;
	t_img		display;
	t_sprite	*sprites;
	t_img		txrn;
	t_img		txrw;
	t_img		txrs;
	t_img		txre;
	t_img		sprite;
	t_img		skybox;
	t_pair		pair;
	char		**file;
	char		**map;
	int			mapon;
	int			c_ceiling;
	int			c_floor;
	int			mm_scale;
	int			m_length;
	int			m_height;
	int			sprite_amount;
	double		grad;
}				t_all;

void	ft_cast_ray(t_all *all);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_put_yellow_square(int x, int y, int width, t_img img);
void	ft_put_red_square(int x, int y, int width, t_img img);
void	set_dxdy(double ddx, double ddy, double *dx, double *dy);
int		set_sprite(t_all *all, char *subline);
int		set_west(t_all *all, char *subline);
int		set_east(t_all *all, char *subline);
int		set_south(t_all *all, char *subline);
int		set_north(t_all *all, char *subline);
int		set_bars(t_all *all, const char *line, int i);
int		set_resolution(t_all *all, const char *line, int i);
int		set_side(t_all *all, const char *line, int i);
int		set_map_params(t_all *all, int i);
char	*make_line(int fd);
int		parse_line(t_all *all, char *line);
char	*line_with_spaces(char *spaces, char *line);
char	*set_model(int length);
int		player_check(t_all *all);
void	sprite_check(t_all *all, int i, int j, int *sprite_count);
int		pl_pos(t_all *all, int i, int j);
int		is_seal(t_all *all, int i, int j);
int		krestik(void);
int		closeboi(int keycode, t_all *all);
int		openboi(int keycode, t_all *all);
int		render_next_frame(t_all *all);
int		args_err(void);
void	ft_make_transparent(int width, int height, t_img img);
void	ft_print_map(t_all *all);
void	setdefault(t_all *all);
void	setimages(t_all *all);
int		no_args_err(void);
int		general_error(void);
void	shrink_screen(t_all *all);
void	save_screen(t_all *all);
void	clear_struct(t_all *all);
void	ft_put_opacity_square(t_all *all);
int		open_file(t_all *all, char *map);
void	movements(t_all *all);
void	ft_nullify(t_img img, int floor, int ceiling);
void	put_vertical(t_all *all, double *lengths, double *zbuf, int i);
void	put_horizontal(t_all *all, double *lengths, double *zbuf, int i);
void	cast_xrays(t_all *all, double ddx, double ddy, double **lengths);
void	cast_yrays(t_all *all, double ddx, double ddy, double **lengths);
void	bubble_sort(t_all *all);
void	minimap_rays(t_all *all, double ddx, double ddy);
void	shave_lines(t_all *all, double *ddx, double *ddy, int i);
void	ft_stripe(int step, double distance, t_pair *pair, int offset);

#endif

/*int		is_all_set(t_all *all);
int		read_file(t_all *all, int fd);
int		parse_setting(t_all *all, char *line, int i);
void		makemap(t_all *all);
int		parse_stuff(t_all *all, char *map);
int		set_ceiling(t_all *all, const char *line, int i);
int		set_floor(t_all *all, const char *line, int i);
int		get_rgb(const char *str, int *i);
int		set_texture(t_all *all, const char *line, int i, int side);
int		set_by_side(t_all *all, char *subline, int side);
void		setimages(t_all *all);
void		setdefault(t_all *all);
void		putsprites(t_all *all, double *zbuf);
int		check_map(t_all *all);
int		make_map(t_all *all, int i);*/
