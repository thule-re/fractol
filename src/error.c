/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:53:56 by treeps            #+#    #+#             */
/*   Updated: 2023/03/15 17:53:59 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	err_exit(void)
{
	ft_printf("usage: fractol <mandelbrot|julia|tricorn> "
		"<opt: julia start value x and y>\n");
	exit(1);
}

void	input_handle(t_data *data, int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		err_exit();
	data->fractal = -1;
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		data->fractal = 0;
	else if (ft_strncmp(argv[1], "julia", 10) == 0)
		data->fractal = 1;
	else if (ft_strncmp(argv[1], "tricorn", 10) == 0)
		data->fractal = 2;
	if (data->fractal == -1)
		err_exit();
	if (argc == 4)
	{
		data->julia_re = linear_scale((int)ft_atoi(argv[2]) % 100, 99, 0, 1);
		data->julia_im = linear_scale((int)ft_atoi(argv[3]) % 100, 99, 0, 1);
	}
}
