/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:18:45 by ajoliet           #+#    #+#             */
/*   Updated: 2022/07/07 18:56:31 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define LIBFT_H

# include "mlx_linux/mlx.h"

typedef struct	s_list
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int		linelen;
	int		endian;
}			t_data;

void	my_pixel_put(t_data *data, int x, int y, int color);
int		main(void);
double	px_to_coor(int px, int pxmax);
int		iter_count(double coorx, double coory);
void	pixel_travel_and_color(void *winptr, int xpxmax, int ypxmax);

#endif
