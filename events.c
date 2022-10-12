/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:00:49 by ajoliet           #+#    #+#             */
/*   Updated: 2022/09/17 17:05:57 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (!*s1++)
			return (0);
	i++;
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_d *d)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		d->gpxd = d->gpxd * 1.5;
		pixel_travel_and_color(d);
	}
	if (button == 4)
	{
		d->gpxd = d->gpxd * 0.75;
		pixel_travel_and_color(d);
	}
	return (0);
}

int	key_hook(int i, t_d *d)
{
	if (i == 101)
		d->iter *= 1.5;
	if (i == 113)
		d->iter *= 0.75;
	if (i == 65364 || i == 's')
		d->gym = d->gym - d->gpxd * 20;
	if (i == 65363 || i == 'd')
		d->gxm = d->gxm + d->gpxd * 20;
	if (i == 65362 || i == 'w')
		d->gym = d->gym + d->gpxd * 20;
	if (i == 65361 || i == 'a')
		d->gxm = d->gxm - d->gpxd * 20;
	if (i == 'l')
		d->xfr += 0.1;
	if (i == 'h')
		d->xfr -= 0.1;
	if (i == 'j')
		d->yfr += 0.1;
	if (i == 'k')
		d->yfr -= 0.1;
	next(i, d);
	return (0);
}

void	next(int i, t_d *d)
{
	if (i == 65507)
		d->gpxd = d->gpxd * 1.5;
	if (i == 32)
		d->gpxd = d->gpxd * 0.75;
	if (i == 65362 || i == 'w')
		d->gym = d->gym + d->gpxd * 20;
	if (i == 65361 || i == 'a')
		d->gxm = d->gxm - d->gpxd * 20;
	if (i == 'l')
		d->xfr += 0.1;
	if (i == 'h')
		d->xfr -= 0.1;
	if (i == 'j')
		d->yfr += 0.1;
	if (i == 'k')
		d->yfr -= 0.1;
	if (i == 65507)
		d->gpxd = d->gpxd * 1.5;
	if (i == 32)
		d->gpxd = d->gpxd * 0.75;
	if (i == 65307)
		cross(d);
	pixel_travel_and_color(d);
}

void	init(t_d *d)
{
	d->img = mlx_new_image(d->mlx, d->smax, d->smax);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->linelen, &d->endian);
	mid_to_start(d);
	d->syc = 0;
	d->sxc = 0;
}
