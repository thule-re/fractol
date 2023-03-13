/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:07:38 by treeps            #+#    #+#             */
/*   Updated: 2023/03/13 16:42:24 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:07:38 by treeps            #+#    #+#             */
/*   Updated: 2023/03/13 15:07:51 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	translate(double x, double y, int *x_cord, int *y_cord)
{
	*x_cord = linear_scale(x, 1, 10, WIDTH - 10);
	*y_cord = linear_scale(y, 1, 10, HEIGHT - 10);
}

void	init_sierpinski(t_data *data)
{
	int	x_cord;
	int	y_cord;

	data->max_iteration = 10000;
	data->fractal = 2;
	data->pos[0] = 0.433;
	data->pos[1] = 0.5;
	data->abc[0][0] = 1.0;
	data->abc[0][1] = 1.0;
	data->abc[1][0] = 0.0;
	data->abc[1][1] = 1.0;
	data->abc[2][0] = 0.5;
	data->abc[2][1] = 0.0;
	translate(data->abc[0][0], data->abc[0][1], &x_cord, &y_cord);
	my_mlx_pixel_put(data, x_cord, y_cord, 0xFF0000);
	translate(data->abc[1][0], data->abc[1][1], &x_cord, &y_cord);
	my_mlx_pixel_put(data, x_cord, y_cord, 0x00FF00);
	translate(data->abc[2][0], data->abc[2][1], &x_cord, &y_cord);
	my_mlx_pixel_put(data, x_cord, y_cord, 0x0000FF);
	translate(data->pos[0], data->pos[1], &x_cord, &y_cord);
	my_mlx_pixel_put(data, x_cord, y_cord, 0xFFFFFF);
}

static int	calc(t_data *data, int x, int y)
{
	int	corner;
	int	x_cord;
	int	y_cord;
	int	i;

	i = 0;
	while (i < data->max_iteration)
	{
		corner = rand() % 3;
		data->pos[0] += (data->abc[corner][0] - data->pos[0]) * 0.5;
		data->pos[1] += (data->abc[corner][1] - data->pos[1]) * 0.5;
		translate(data->pos[0], data->pos[1], &x_cord, &y_cord);
		i++;
		if (x_cord == x && y_cord == y)
			return (i);
	}
	return (i);
}

static void	put(t_data *data)
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

int	put_sierpinski(t_data *data)
{
	// calc(data);
	put(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
