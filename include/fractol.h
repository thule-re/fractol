/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:35:14 by treeps            #+#    #+#             */
/*   Updated: 2023/03/13 15:07:04 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "keycodes.h"
# include <math.h>

# define HEIGHT 540
# define WIDTH  960

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		max_iteration;
	int		color_set;
	int		fractal;
	double	lum;
	double	lum_min;
	double	lum_max;
	double	lum_offset;
	int		animate;

	double	julia_re;
	double	julia_im;
	int		unlock;

	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	zoom_factor;

	double	abc[3][2];
	double	pos[2];
}				t_data;

// init
void	welcome(void);
void	init_mlx(t_data *data);
void	init_mandelbrot(t_data *data);
void	init_julia(t_data *data);
void	init_tricorn(t_data *data);
void	reset_fractal(t_data *data);

// hook
int		key_hook(int k, t_data *data);
int		loop_hook(t_data *data);
int		destroy_hook(t_data *data);
int		mouse_hook(int k, int x, int y, t_data *data);

// utils
void	toggle(int *bool);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	input_handle(t_data *data, int argc, char **argv);
void	err_exit(void);

// color
int		get_trgb(double r, double g, double b);
int		get_color(t_data *data, int iteration);
int		bw(t_data *data, int iteration);
int		red(t_data *data, int iteration);
int		green(t_data *data, int iteration);
int		blue(t_data *data, int iteration);
int		trip(t_data *data, int iteration);
int		colorful(t_data *data, int iteration);

// math
double	linear_scale(double n, double r_max, double t_min, double t_max);
double	exponential_scale(double n, double r_max, double lum);

// move
void	move(t_data *data, int dir);

// zoom
void	zoom_increase(t_data *data, int x, int y);
void	zoom_decrease(t_data *data, int x, int y);

// fractals
int		put_mandelbrot(t_data *data);
int		put_julia(t_data *data);
int		put_tricorn(t_data *data);

#endif
