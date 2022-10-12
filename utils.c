/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:24:56 by ajoliet           #+#    #+#             */
/*   Updated: 2022/09/17 17:33:55 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_d *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->linelen + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

int	cross(t_d *d)
{
	mlx_loop_end(d->mlx);
	return (0);
}

void	set_n(long double x, long double y, t_d *d)
{
	d->xfr = x;
	d->yfr = y;
}

int	printparams(void)
{
	int	i;

	i = write(1, "paramètres : mandelbrot ou julia1->julia4\n", 46);
	i = 0;
	return (i);
}

void	mid_to_start(t_d *d)
{
	d->gxs = d->gxm - 0.5 * (long double)d->smax * d->gpxd;
	d->gys = d->gym + 0.5 * (long double)d->smax * d->gpxd;
}
