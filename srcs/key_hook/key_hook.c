/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 13:05:58 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/05/18 13:06:01 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	get_fract(t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	if (all->fract == 1)
		julia(&all->coord, &*all);
	if (all->fract == 2)
		mandelbrot(&all->coord, &*all);
	if (all->fract == 3)
		burningship(&all->coord, &*all);
	if (all->fract == 4)
		yolo(&all->coord, &*all);
	if (all->fract == 5)
		shiva(&all->coord, &*all);
	if (all->fract == 6)
		hotblood(&all->coord, &*all);
	if (all->fract == 7)
		goldenratio(&all->coord, &*all);
	if (all->fract == 8)
		tricorn(&all->coord, &*all);
}

void	reset_fract(t_all *all, int key)
{
	mlx_clear_window(all->mlx, all->win);
	if (key == 18)
		main_julia(&*all);
	if (key == 19)
		main_mandelbrot(&*all);
	if (key == 20)
		main_burningship(&*all);
	if (key == 21)
		main_yolo(&*all);
	if (key == 23)
		main_shiva(&*all);
	if (key == 22)
		main_hotblood(&*all);
	if (key == 26)
		main_goldenratio(&*all);
	if (key == 28)
		main_tricorn(&*all);
	if (key == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		mlx_destroy_image(all->mlx, all->img.img);
		exit((int)all->mlx);
	}
}

int		mlx_funct_key(int keycode, t_all *all)
{
	keycode == 257 ? ++all->m : 0;
	keycode == 69 ? ++all->coord.iteration : 0;
	keycode == 78 && all->coord.iteration > 1 ?\
	--all->coord.iteration : 0;
	keycode == 49 ? ++all->coord.stop : 0;
	keycode == 15 && all->coord.r < 255 ? all->coord.r += 1 : 0;
	keycode == 17 && all->coord.r > 0 ? all->coord.r -= 1 : 0;
	keycode == 5 && all->coord.g < 255 ? all->coord.g += 1 : 0;
	keycode == 4 && all->coord.g > 0 ? all->coord.g -= 1 : 0;
	keycode == 11 && all->coord.b < 255 ? all->coord.b += 1 : 0;
	keycode == 45 && all->coord.b > 0 ? all->coord.b -= 1 : 0;
	mlx_funct(keycode, &*all);
	reset_fract(&*all, keycode);
	get_fract(&*all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	menu(&*all);
	keycode == 17 ? exit((int)all->mlx) : 0;
	return (0);
}

int		mlx_funct_mouse(int keymouse, int x, int y, t_all *all)
{
	if (keymouse == 4)
	{
		all->coord.x_r = (x / all->coord.zoom) + all->coord.x1;
		all->coord.y_r = (y / all->coord.zoom) + all->coord.y1;
		all->coord.zoom *= 1.1;
		all->coord.mousezx = all->coord.x_r - (x / all->coord.zoom);
		all->coord.mousezy = all->coord.y_r - (y / all->coord.zoom);
		get_fract(&*all);
		mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
		menu(&*all);
	}
	if (keymouse == 5)
	{
		all->coord.x_r = (x / all->coord.zoom) + all->coord.x1;
		all->coord.y_r = (y / all->coord.zoom) + all->coord.y1;
		all->coord.zoom /= 1.1;
		all->coord.mousezx = all->coord.x_r - (x / all->coord.zoom);
		all->coord.mousezy = all->coord.y_r - (y / all->coord.zoom);
		get_fract(&*all);
		mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
		menu(&*all);
	}
	return (0);
}

int		mlx_hook_mov(int x, int y, t_all *all)
{
	t_coord coord;

	coord = all->coord;
	if (!(all->coord.stop % 2))
	{
		all->coord.mousex = ((double)x - (I_Y)) / 1000;
		all->coord.mousey = ((double)y - (I_Y / 2)) / 1000;
		get_fract(&*all);
		mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
		menu(&*all);
	}
	return (0);
}
