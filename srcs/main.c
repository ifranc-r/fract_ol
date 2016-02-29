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


#include "../includes/fract_ol.h"

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
	all->img.img = mlx_new_image(all->mlx, WIN_X - 50, WIN_Y - 50);
}

static void		set_color(t_color *color)
{
	color->red = 255;
	color->green = 255;
	color->blue = 255;
	color->alpha = 1;
}

static void		mlx_image(t_all *all, t_img *img)
{
	int  size;

	size = (((WIN_X - 200) * 4) +((WIN_Y - 200) * img->size));
	img->data[size] =  all->color.red;
	img->data[size + 1] =  all->color.green;
	img->data[size + 2] =  all->color.blue;
	img->data[size + 3] =  all->color.alpha;
}

int		main(void)
{
	t_all	all;

	init_mlx(&all);
	all.img.data = mlx_get_data_addr(all.img.img, &all.img.bitpx, &all.img.size, &all.img.endian);
	set_color(&all.color);
	mlx_image(&all, &all.img);
	mlx_put_image_to_window(all.mlx, all.win, all.img.img, 30, 30);
	mlx_key_hook(all.win, mlx_funct_key, all.mlx);
	mlx_loop(all.mlx);
}