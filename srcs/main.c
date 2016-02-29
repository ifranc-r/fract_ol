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

int		mlx_funct_key(int keycode, void *mlx)
{
	printf("key event %d\n", keycode);
	if (keycode == 53) // Bouton echap
		exit((int)mlx);
	return (0);
}

static void		init_mlx(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIN_X, WIN_Y, "fract'ol");
	all->img.img = mlx_new_image(all->mlx, WIN_X - 100, WIN_Y - 100);
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

	size = (((WIN_X) * 4) +(WIN_Y * img->size));
	img->data[size] =  mlx_get_color_value(all->mlx, all->color.red);
	img->data[size + 1] =  mlx_get_color_value(all->mlx, all->color.green);
	img->data[size + 2] =  mlx_get_color_value(all->mlx, all->color.blue);
}

int		main(void)
{
	t_all	all;

	init_mlx(&all);
	all.img.data = mlx_get_data_addr(all.img.data, &all.img.bitpx, &all.img.size, &all.img.endian);
	set_color(&all.color, 125, 125, 125);
	mlx_image(&all, &all.img);
	mlx_put_image_to_window(all.mlx, all.win, all.img.img, 0, 0);
	mlx_key_hook(all.win, mlx_funct_key, all.mlx);
	mlx_loop(all.mlx);
}