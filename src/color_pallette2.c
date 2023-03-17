/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pallette2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:21:24 by treeps            #+#    #+#             */
/*   Updated: 2023/03/10 15:21:28 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	trip(t_data *data, int iteration)
{
	double	t;
	double	r;
	double	g;
	double	b;

	t = exponential_scale(iteration, data->max_iteration, data->lum);
	r = fmod(9.4 * (1 - t) * t * t * t, 1.0);
	g = fmod(15.9 * (1 - t) * (1 - t) * t * t, 1.0);
	b = fmod(9.4 * (1 - t) * (1 - t) * (1 - t) * t, 1.0);
	return (get_trgb(r, g, b));
}

/*
(1 - t) * t^3
(1 - t)^2 * t^2
(1 - t)^3 * t
 */