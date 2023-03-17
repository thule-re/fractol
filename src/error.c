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
