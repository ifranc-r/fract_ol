/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:37:14 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/29 17:39:23 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include <math.h>
# define WIN_X 1920
# define WIN_Y 1080

typedef struct	s_color
{
	int		red;
	int		blue;
	int 	green;
	int		alpha;
}				t_color;

typedef struct	s_img
{
	void	*img;
	char	*data;
	int		bitpx;
	int		size;
	int		endian;
}				t_img;

typedef struct	s_all
{
	struct	s_color color;
	struct 	s_img	img;
	void	*mlx;
	void	*win;
}				t_all;

#endif
