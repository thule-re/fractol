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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:35:14 by treeps            #+#    #+#             */
/*   Updated: 2023/03/13 13:44:06 by treeps           ###   ########.fr       */
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
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;


	double	abc[3][2];
	double	pos[2];
}				t_data;


// hook
int		key_hook(int k, t_data *data);
int		loop_hook(t_data *data);
int		destroy_hook(t_data *data);
int		mouse_hook(int k, int x, int y, t_data *data);

// utils
void	toggle(int *bool);

// color
int		get_trgb(double t, double r, double g, double b);
int		get_color(t_data *data, int iteration);
int		bw(t_data *data, int iteration);
int		red(t_data *data, int iteration);
int		green(t_data *data, int iteration);
int		blue(t_data *data, int iteration);
int		trip(t_data *data, int iteration);
int		lch(t_data *data, int iteration);
int		interpolate(t_data *data, int iteration, int col1, int col2);

// math
double	linear_scale(double n, double r_max, double t_min, double t_max);
double	exponential_scale(double n, double r_max, double lum);

// pixelput
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// mandelbrot
void	init_mandelbrot(t_data *data);
int		put_mandelbrot(t_data *data);

// julia
void	init_julia(t_data *data);
int		put_julia(t_data *data);

// sierpinski
void	init_sierpinski(t_data *data);
int		put_sierpinski(t_data *data);

#endif
