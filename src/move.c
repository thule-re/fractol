/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:52 by treeps            #+#    #+#             */
/*   Updated: 2023/03/15 15:04:56 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	move_left(t_data *data)
{
	double	scale;

	scale = (data->max_re - data->min_re) / WIDTH;
	data->max_re -= scale * 10;
	data->min_re -= scale * 10;
}

static void	move_right(t_data *data)
{
	double	scale;

	scale = (data->max_re - data->min_re) / WIDTH;
	data->max_re += scale * 10;
	data->min_re += scale * 10;
}

static void	move_up(t_data *data)
{
	double	scale;

	scale = (data->max_im - data->min_im) / HEIGHT;
	data->max_im += scale * 10;
	data->min_im += scale * 10;
}

static void	move_down(t_data *data)
{
	double	scale;

	scale = (data->max_im - data->min_im) / HEIGHT;
	data->max_im -= scale * 10;
	data->min_im -= scale * 10;
}

void	move(t_data *data, int dir)
{
	if (dir == 0)
		move_left(data);
	else if (dir == 1)
		move_right(data);
	else if (dir == 2)
		move_down(data);
	else if (dir == 3)
		move_up(data);
}
