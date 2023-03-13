/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pallette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:21:24 by treeps            #+#    #+#             */
/*   Updated: 2023/03/10 15:21:28 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	bw(t_data *data, int iteration)
{
	double	r;
	double	g;
	double	b;

	r = linear_scale(iteration, data->max_iteration, 0, 1);
	g = linear_scale(iteration, data->max_iteration, 0, 1);
	b = linear_scale(iteration, data->max_iteration, 0, 1);
	return (get_trgb(0, r, g, b));
}

int	red(t_data *data, int iteration)
{
	double	r;
	double	g;
	double	b;

	r = linear_scale(iteration, data->max_iteration, 0, 1);
	g = 0;
	b = 0;
	return (get_trgb(0, r, g, b));
}

int	green(t_data *data, int iteration)
{
	double	r;
	double	g;
	double	b;

	r = 0;
	g = linear_scale(iteration, data->max_iteration, 0, 1);
	b = 0;
	return (get_trgb(0, r, g, b));
}

int	blue(t_data *data, int iteration)
{
	double	r;
	double	g;
	double	b;

	r = 0;
	g = 0;
	b = linear_scale(iteration, data->max_iteration, 0, 1);
	return (get_trgb(0, r, g, b));
}

int	trip(t_data *data, int iteration)
{
	double	t;
	double	r;
	double	g;
	double	b;

	t = (double)iteration / 255.0;
	t = exponential_scale(iteration, data->max_iteration, data->lum);
	r = 9.4 * (1 - t) * t * t * t;
	g = 15.9 * (1 - t) * (1 - t) * t * t;
	b = 9.4 * (1 - t) * (1 - t) * (1 - t) * t;


	return (get_trgb(0, r, g, b));
}

/*
(1 - t) * t^3
(1 - t)^2 * t^2
(1 - t)^3 * t
 */