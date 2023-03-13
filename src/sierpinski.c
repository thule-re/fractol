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

void	init_sierpinski(t_data *data)
{
	data->max_iteration = 1;
	data->color_set = 420;
	data->lum_min = -3;
	data->lum_max = 1.5;
	data->lum = data->lum_min;
	data->lum_offset = 0.01;
}

static void	calc(t_data *data)
{
	static int	arr[1000][1000];
	int			corner_abc[3][2];

	corner_abc[0][0] = 0;
	corner_abc[0][1] = 0;
	corner_abc[1][0] = 1000;
	corner_abc[1][1] = 0;
	corner_abc[2][0] = 500;
	corner_abc[2][1] = 1000;
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
			calc(data);
			color = get_color(data, iteration);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

int	put_sierpinski(t_data *data)
{
	put_picture(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	data->max_iteration++;
	return (0);
}
