/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:06 by ajoliet           #+#    #+#             */
/*   Updated: 2022/07/07 19:46:37 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	my_pixel_put(t_data *data, int x, int y, int color)
{
		char	*dst;

		dst = data->addr + (y * data->linelen + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*winptr;
	t_data	img;
	int		i;
	int 	x;
	int 	y;

	y = 800;
	x = 800;
	i = 0;
	mlx = mlx_init();
	winptr = mlx_new_window(mlx, x, y, "oui");
	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.linelen, &img.endian);
	while (i < 50)
	{
		pixel_travel_and_color(&img, x, y);
		i++;
	}
	mlx_put_image_to_window(mlx, winptr, img.img, 0, 0);
	mlx_loop(mlx);	
}

double	px_to_coor(int px, int pxmax)
{
	double	coor;

	coor = ((double)px / (double)pxmax) * 4.0 - 2.0;
	return (coor);
}

int	iter_count(double coorx, double coory)
{
	double	xtmp;
	double	ytmp;
	int 	count;
	
	count = 1;
	while (count < 50)
	{
		xtmp = coorx;
		ytmp = coory;
		coorx = xtmp * xtmp - ytmp * ytmp - 0.751;
		coory = 2 * xtmp * ytmp + 0;
		if (coorx * coorx > 2 || coory * coory > 2)
				return (count);
		count++;
	}
	return (count);
}

void	pixel_travel_and_color(void *img, int xpxmax, int ypxmax)
{
	int		x;
	int		y;
	int		count;
	int 	cmax;

	cmax = 50;
	x = 0;
	y = 0;
	while (y < ypxmax)
	{
		while (x < xpxmax)
		{
			count = iter_count(px_to_coor(x, xpxmax), px_to_coor(y, ypxmax));	
//			printf("%2d", count);
			if (count == cmax)
				my_pixel_put(img, x, y, 0x00000000);
			if (count < cmax)
				my_pixel_put(img, x, y, 0x00FF0000 + count *  10);
			x++;
		}
		x = 0;
//		printf("\n");
		y++;
	}
}
