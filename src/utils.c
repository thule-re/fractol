/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:42:00 by treeps            #+#    #+#             */
/*   Updated: 2023/03/10 14:42:03 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	toggle(int *bool)
{
	if (*bool == 1)
		*bool = 0;
	else if (*bool == 0)
		*bool = 1;
}

double	linear_scale(double n, double r_max, double t_min, double t_max)
{
	double	r_range;
	double	t_range;
	double	factor;
	double	scaled;

	r_range = r_max;
	t_range = t_max - t_min;
	factor = t_range / r_range;
	scaled = (n) * factor + t_min;
	return (scaled);
}

double	exponential_scale(double n, double r_max, double lum)
{
	double	factor;
	double	scale;
	double	_lum;

	_lum = linear_scale(lum, 1, 0.25, 0.6);
	factor = linear_scale(n, r_max, 0, 1);
	scale = 0.5 * pow(M_E, factor) - _lum;
	return (scale);
}
