/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:14:01 by treeps            #+#    #+#             */
/*   Updated: 2023/03/15 16:38:25 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int k, t_data *data)
{
	if (k == KEY_ESCAPE)
		destroy_hook(data);
	else if (k == KEY_SPACE)
		toggle(&data->animate);
	else if (k == KEY_U)
		toggle(&data->unlock);
	else if (k == KEY_R)
		reset_fractal(data, data->fractal);
	else if (k == KEY_A || k == KEY_S || k == KEY_D)
		reset_fractal(data, k);
	else if (k == KEY_PLUS)
		data->max_iteration += 5;
	else if (k == KEY_MINUS)
		data->max_iteration -= 5;
	else if (k >= KEY_1 && k <= KEY_6)
		data->color_set = k - KEY_1;
	else if (k >= KEY_LEFT && k <= KEY_DOWN)
		move(data, k);
	return (k);
}

int	destroy_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
}

int	loop_hook(t_data *data)
{
	int	x;
	int	y;

	if (data->unlock)
	{
		mlx_mouse_get_pos(data->mlx, data->mlx_win, &x, &y);
		data->julia_re = linear_scale(x, WIDTH, data->min_re, data->max_re);
		data->julia_im = linear_scale(y, HEIGHT, data->min_im, data->max_im);
	}
	if (data->animate && data->color_set == 5)
	{
		if (data->lum > data->lum_max)
			data->lum = data->lum_min;
		data->lum += data->lum_offset;
	}
	if (data->fractal == 0)
		put_mandelbrot(data);
	else if (data->fractal == 1)
		put_julia(data);
	else if (data->fractal == 2)
		put_tricorn(data);
	return (0);
}

int	mouse_hook(int k, int x, int y, t_data *data)
{
	if (k == 1)
	{
		if (data->unlock == 1)
			data->unlock = 0;
		else
		{
			data->julia_re = linear_scale(x, WIDTH, \
			data->min_re, data->max_re);
			data->julia_im = linear_scale(y, HEIGHT, \
			data->min_im, data->max_im);
		}
	}
	if (k == 5)
		zoom_increase(data, x, y);
	if (k == 4)
		zoom_decrease(data, x, y);
	return (0);
}
