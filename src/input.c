/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsbur>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:25:11 by treeps            #+#    #+#             */
/*   Updated: 2023/03/17 12:25:15 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	input_handle(t_data *data, int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		err_exit();
	data->fractal = -1;
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		init_mandelbrot(data);
	else if (ft_strncmp(argv[1], "julia", 10) == 0)
		init_julia(data);
	else if (ft_strncmp(argv[1], "tricorn", 10) == 0)
		init_tricorn(data);
	if (data->fractal == -1)
		err_exit();
	if (argc == 4)
	{
		data->julia_re = linear_scale((int)ft_atoi(argv[2]) % 100, 99, 0, 1);
		data->julia_im = linear_scale((int)ft_atoi(argv[3]) % 100, 99, 0, 1);
	}
}

void	welcome(void)
{
	ft_printf("\n---        Fractol        ---\n");
	ft_printf("\ncontrols:\n\n");
	ft_printf("<a/s/d>              switch fractal\n");
	ft_printf("<1/2/3/4/5/6>        switch color\n");
	ft_printf("<space>              start/stop color animation (mode 6 only)\n");
	ft_printf("<arrow keys>         move\n");
	ft_printf("<r>                  reset\n");
	ft_printf("<u>                  (un)lock julia\n");
	ft_printf("<scroll>             zoom\n");
	ft_printf("<left_click>         new julia constant\n");
	ft_printf("<ESC>                exit program\n");
	ft_printf("\n");
}
