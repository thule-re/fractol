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

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	mlx_hook(data->mlx_win, 2, 4, key_hook, data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("usage: fractol <mandelbrot|julia|sierpinski>\n");
		exit(1);
	}
	init(&data);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		init_mandelbrot(&data);
		mlx_loop_hook(data.mlx, put_mandelbrot, &data);
	}
	if (ft_strncmp(argv[1], "sierpinski", 10) == 0)
	{
		init_sierpinski(&data);
		mlx_loop_hook(data.mlx, put_sierpinski, &data);
	}
	mlx_loop(data.mlx);
}
