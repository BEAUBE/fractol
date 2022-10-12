/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:06 by ajoliet           #+#    #+#             */
/*   Updated: 2022/09/17 17:31:49 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_d		d;

	d.mandelbrot = 0;
	d.gxm = 0;
	d.gym = 0;
	d.gpxd = 0.005;
	d.smax = 800;
	d.iter = 50;
	d.img = NULL;
	if (ctn(ac, av, &d))
	{
		d.mlx = mlx_init();
		d.winptr = mlx_new_window(d.mlx, d.smax, d.smax, "fractol");
		pixel_travel_and_color(&d);
		mlx_key_hook(d.winptr, key_hook, &d);
		mlx_hook(d.winptr, 4, 1L << 2, mouse_hook, &d);
		mlx_hook(d.winptr, 17, 1L << 17, cross, &d);
		mlx_loop(d.mlx);
		mlx_clear_window(d.mlx, d.winptr);
		mlx_destroy_window(d.mlx, d.winptr);
		mlx_destroy_display(d.mlx);
		free(d.mlx);
	}
}

int	ctn(int ac, char **av, t_d *d)
{
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 12))
		{
			d->mandelbrot = 1;
			set_n(0.00, 0.00, d);
		}
		else if (!ft_strncmp(av[1], "julia4", 6))
			set_n(-0.75, 0.00, d);
		else if (!ft_strncmp(av[1], "julia1", 6))
			set_n(-0.12, 0.75, d);
		else if (!ft_strncmp(av[1], "julia2", 6))
			set_n(0.00, 1.00, d);
		else if (!ft_strncmp(av[1], "julia3", 6))
			set_n(-0.39, -0.59, d);
		else
			return (printparams());
	}
	else
		return (printparams());
	return (1);
}

int	ma(long double coorx, long double coory, t_d *d)
{
	long double	xtmp;
	long double	ytmp;
	int			count;

	count = 1;
	xtmp = 0;
	ytmp = 0;
	d->xfr = coorx;
	d->yfr = coory;
	while (count < d->iter && coorx * coorx + coory * coory < 4)
	{
		coorx = xtmp * xtmp - ytmp * ytmp + d->xfr;
		coory = 2 * xtmp * ytmp + d->yfr;
		count++;
		xtmp = coorx;
		ytmp = coory;
	}
	return (count);
}

int	ju(long double coorx, long double coory, t_d *d)
{
	long double	xtmp;
	long double	ytmp;
	int			count;

	count = 1;
	while (count < d->iter)
	{
		xtmp = coorx;
		ytmp = coory;
		coorx = xtmp * xtmp - ytmp * ytmp - d->xfr;
		coory = 2 * xtmp * ytmp + d->yfr;
		if (coorx * coorx + coory * coory > 4)
			return (count);
		count++;
	}
	return (count);
}

void	pixel_travel_and_color(t_d *d)
{
	int	c;

	init(d);
	while (d->syc < d->smax)
	{
		while (d->sxc < d->smax)
		{
			c = 0;
			if (d->mandelbrot == 0)
				c = ju(d->gxs + d->sxc * d->gpxd, d->gys - d->syc * d->gpxd, d);
			else
				c = ma(d->gxs + d->sxc * d->gpxd, d->gys - d->syc * d->gpxd, d);
			if (c == d->iter)
				my_pixel_put(d, d->sxc, d->syc, 0x00000000);
			if (c < d->iter)
				my_pixel_put(d, d->sxc, d->syc, 0x00FF0FF0 * c * 15);
			d->sxc++;
		}
		d->sxc = 0;
		d->syc++;
	}
	mlx_put_image_to_window(d->mlx, d->winptr, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
}
