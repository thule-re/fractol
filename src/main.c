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

	init_fractal(&data);
	input_handle(&data, argc, argv);
	init_toggles(&data);
	init_mlx(&data);
	welcome();
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
