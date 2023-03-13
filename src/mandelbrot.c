/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:41:10 by treeps            #+#    #+#             */
/*   Updated: 2023/03/10 14:41:13 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mandelbrot(t_data *data)
{
	data->min_re = -2.51;
	data->max_re = 1.5;
	data->min_im = -1.12;
	data->max_im = 1.12;
	data->max_iteration = 100;
	data->color_set = 420;
	data->lum_min = -3;
	data->lum_max = 1.5;
	data->lum = data->lum_min;
	data->lum_offset = 0.01;
}

static int	calc(t_data *data, double x_cord, double y_cord)
{
	double	x;
	double	y;
	int		i;
	double	temp;

	x_cord = linear_scale(x_cord, WIDTH, data->min_re \
	, data->max_re);
	y_cord = linear_scale(y_cord, HEIGHT, data->min_im \
	, data->max_im);
	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4.5 && i < data->max_iteration)
	{
		temp = x * x - y * y + x_cord;
		y = 2 * x * y + y_cord;
		x = temp;
		i++;
	}
	return (i);
}

static void	put_picture(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	iteration;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iteration = calc(data, x, y);
			color = get_color(data, iteration);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

int	put_mandelbrot(t_data *data)
{
	put_picture(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	if (data->lum > data->lum_max || data->lum < data->lum_min)
		data->lum_offset *= -1;
	data->lum += data->lum_offset;
	return (0);
}
