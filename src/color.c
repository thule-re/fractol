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

int	get_trgb(double t, double r, double g, double b)
{
	int	trgb;

	trgb = 0;
	trgb += t * 255;
	trgb <<= 8;
	trgb += r * 255;
	trgb <<= 8;
	trgb += g * 255;
	trgb <<= 8;
	trgb += b * 255;
	return (trgb);
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
	if (data->color_set == 420)
		return (trip(data, iteration));
	return (bw(data, iteration));
}
