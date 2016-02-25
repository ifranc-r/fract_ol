/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:35:46 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/25 17:35:56 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fract_ol.h"

static void		init_mlx(t_all *all)
{
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, WIN_X, WIN_Y, "fract'ol");
	all.img.img = mlx_new_image(void *mlx,int width,int height);
}

static void		set_color(t_color *color, int r, int g, int b)
{
	color->red = r;
	color->green = g;
	color->blue = b;
}

static void		mlx_image(t_all *all, t_img *img)
{
	int  size;

	size = (((WIN_X / 3) + (WIN_Y / 3)) * 4);
	if ((coord->x >= 0) && (coord->y >= 0))
	{
		img->data[size] =  mlx_get_color_value(all.mlx, all.color->red);
		img->data[size + 1] =  mlx_get_color_value(all.mlx, all.color->green);
		img->data[size + 2] =  mlx_get_color_value(all.mlx, all.color->blue);
	}
}

int		main(int argc, char **argv)
{
	t_all	all;

	init_mlx(&all);
	all.img.data = mlx_get_data_addr(all.img.data, &all.img.bitpx, &all.img.size, &all.img.endian);
	set_color(&all.color, 125, 125, 125);
	mlx_image(&all.img, &all.color, &all);
}
