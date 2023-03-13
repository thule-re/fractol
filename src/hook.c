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
	return (k);
}

int	loop_hook(t_data *data)
{
	if (data->fractal == 0)
		put_mandelbrot(data);
	if (data->fractal == 1)
		;
		// put_julia(data);
	if (data->fractal == 2)
		put_sierpinski(data);
	return (0);
}
