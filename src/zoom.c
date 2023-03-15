/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:22:46 by treeps            #+#    #+#             */
/*   Updated: 2023/03/15 12:22:50 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_increase(t_data *data, int x, int y)
{
	double	x_scale;
	double	y_scale;

	x_scale = (data->max_re - data->min_re) / WIDTH;
	y_scale = (data->max_im - data->min_im) / HEIGHT;
	data->min_im += y_scale * y * data->zoom_factor;
	data->max_im -= y_scale * (HEIGHT - y) * data->zoom_factor;
	data->min_re += x_scale * x * data->zoom_factor;
	data->max_re -= x_scale * (WIDTH - x) * data->zoom_factor;
}

void	zoom_decrease(t_data *data, int x, int y)
{
	double	x_scale;
	double	y_scale;

	x_scale = (data->max_re - data->min_re) / WIDTH;
	y_scale = (data->max_im - data->min_im) / HEIGHT;
	data->min_im -= y_scale * y * data->zoom_factor;
	data->max_im += y_scale * (HEIGHT - y) * data->zoom_factor;
	data->min_re -= x_scale * x * data->zoom_factor;
	data->max_re += x_scale * (WIDTH - x) * data->zoom_factor;
}
