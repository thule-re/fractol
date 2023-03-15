/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:35:04 by treeps            #+#    #+#             */
/*   Updated: 2023/03/09 14:38:35 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2 || argc > 3)
	{
		ft_printf("usage: fractol <mandelbrot|julia|tricorn> \
				  <opt: julia start value>\n");
		exit(1);
	}
	init(&data);
	init_fractal(&data);
	init_toggles(&data);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		data.fractal = 0;
	else if (ft_strncmp(argv[1], "julia", 10) == 0)
		data.fractal = 1;
	else if (ft_strncmp(argv[1], "tricorn", 10) == 0)
		data.fractal = 2;
	else
	{
		ft_printf("usage: fractol <mandelbrot|julia|tricorn>\n");
		exit(1);
	}
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
