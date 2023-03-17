/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:22:37 by treeps            #+#    #+#             */
/*   Updated: 2023/03/17 12:28:27 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:37:25 by treeps            #+#    #+#             */
/*   Updated: 2023/03/15 18:42:18 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mandelbrot(t_data *data)
{
	data->fractal = 0;
	data->max_iteration = 20;
	data->min_re = -2.51;
	data->max_re = 1.5;
	data->min_im = -1.12;
	data->max_im = 1.12;
	data->color_set = 1;
	data->lum_min = -2.5;
	data->lum_max = 2.25;
	data->lum = -1.3;
	data->lum_offset = 0.1;
	data->zoom_factor = 0.5;
	data->unlock = 0;
	data->animate = 1;
}

void	init_julia(t_data *data)
{
	data->fractal = 1;
	data->max_iteration = 20;
	data->min_re = -2;
	data->max_re = 2;
	data->min_im = -1.12;
	data->max_im = 1.12;
	data->julia_re = -0.904167;
	data->julia_im = -0.277926;
	data->color_set = 1;
	data->lum_min = -2.5;
	data->lum_max = 2.25;
	data->lum = -1.3;
	data->lum_offset = 0.1;
	data->zoom_factor = 0.5;
	data->unlock = 0;
	data->animate = 1;
}

void	init_tricorn(t_data *data)
{
	data->fractal = 2;
	data->min_re = -3.371864;
	data->max_re = 3.051381;
	data->min_im = -1.830843;
	data->max_im = 1.757204;
	data->color_set = 1;
	data->lum_min = -2.5;
	data->lum_max = 2.25;
	data->lum = -1.3;
	data->lum_offset = 0.1;
	data->zoom_factor = 0.5;
	data->unlock = 0;
	data->animate = 1;
}

void	reset_fractal(t_data *data, int fractal)
{
	if (fractal == 0)
		init_mandelbrot(data);
	else if (fractal == 1)
		init_julia(data);
	else if (fractal == 2)
		init_tricorn(data);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 0, key_hook, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0, destroy_hook, data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_do_key_autorepeaton(data->mlx);
}
