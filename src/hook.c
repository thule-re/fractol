/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:14:01 by treeps            #+#    #+#             */
/*   Updated: 2023/03/09 16:14:01 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int k, t_data *data)
{
	if (k == KEY_ESCAPE)
	{
		mlx_destroy_image(data->mlx, data->img);
		exit(0);
	}
	if (k == KEY_SPACE)
		toggle(&data->animate);
	return (k);
}

int	destroy_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	exit(0);
}

int	loop_hook(t_data *data)
{
	if (data->fractal == 0)
		put_mandelbrot(data);
	if (data->fractal == 1)
		put_julia(data);
	if (data->fractal == 2)
		put_sierpinski(data);
	return (0);
}

int	mouse_hook(int k, int x, int y, t_data *data)
{
	if (k == 1)
	{
		data->julia_re = linear_scale(x, WIDTH, data->min_re, data->max_re);
		data->julia_im = linear_scale(y, HEIGHT, data->min_im, data->max_im);
	}
	return (0);
}
