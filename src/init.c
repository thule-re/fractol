/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:37:25 by treeps            #+#    #+#             */
/*   Updated: 2023/03/15 16:37:27 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractal(t_data *data)
{
	data->max_iteration = 20;
	data->min_re = -2.51;
	data->max_re = 1.5;
	data->min_im = -1.12;
	data->max_im = 1.12;
	data->julia_re = 0.0;
	data->julia_im = 0.0;
	data->color_set = 1;
	data->lum_min = -5;
	data->lum_max = 1.5;
	data->lum = -1.3;
	data->lum_offset = 0.01;
	data->zoom_factor = 0.5;
}

void	init_toggles(t_data *data)
{
	data->unlock = 0;
	data->animate = 0;
}

void	init(t_data *data)
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
