/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:18:45 by ajoliet           #+#    #+#             */
/*   Updated: 2022/09/17 17:22:24 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define LIBFT_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_d
{
	int			mandelbrot;
	long double	xfr;
	long double	yfr;
	int			iter;
	void		*winptr;
	void		*mlx;
	long double	sxc;
	long double	syc;
	long double	gpxd;
	long double	gxm;
	long double	gym;
	long double	gxs;
	long double	gys;
	int			smax;
	void		*img;
	char		*addr;
	int			bpp;
	int			linelen;
	int			endian;
}			t_d;

int			mouse_hook(int button, int x, int y, t_d *d);
int			cross(t_d *d);
long double	px_to_coor(t_d *d, int px, int pxmax);
int			ju(long double coorx, long double coory, t_d *d);
int			ma(long double coorx, long double doory, t_d *d);
void		pixel_travel_and_color(t_d *d);
int			key_hook(int i, t_d *d);
int			ctn(int ac, char **av, t_d *d);
void		set_n(long double x, long double y, t_d *d);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		my_pixel_put(t_d *d, int x, int y, int color);
void		next(int i, t_d *d);
int			printparams(void);
void		mid_to_start(t_d *d);
void		init(t_d *d);

#endif
