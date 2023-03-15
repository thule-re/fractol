/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:20:07 by treeps            #+#    #+#             */
/*   Updated: 2023/03/10 15:08:36 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_trgb(double r, double g, double b)
{
	int	rgb;

	rgb = 0x0;
	rgb <<= 8;
	rgb += r * 255;
	rgb <<= 8;
	rgb += g * 255;
	rgb <<= 8;
	rgb += b * 255;
	return (rgb);
}

int	get_color(t_data *data, int iteration)
{
	if (iteration == data->max_iteration)
		return (0);
	if (data->color_set == 0)
		return (bw(data, iteration));
	if (data->color_set == 1)
		return (red(data, iteration));
	if (data->color_set == 2)
		return (green(data, iteration));
	if (data->color_set == 3)
		return (blue(data, iteration));
	if (data->color_set == 5)
		return (colorful(data, iteration));
	if (data->color_set == 4)
		return (trip(data, iteration));
	return (bw(data, iteration));
}
