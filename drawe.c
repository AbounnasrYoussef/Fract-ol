/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:21:12 by yabounna          #+#    #+#             */
/*   Updated: 2025/03/15 13:22:53 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	is_julia(t_complexe *z, t_complexe *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->real = fractal->julia_r;
		c->img = fractal->julia_im;
	}
	else
	{
		c->real = z->real;
		c->img = z->img;
	}
}

void	draw_pixel(int x, int y, t_fractal *fractal)
{
	t_complexe	z;
	t_complexe	c;
	int			i;
	int			color;

	i = 0;
	color = 0;
	z.real = pixel_to_math(x, -2, 2, WIDTH) * fractal->zoom;
	z.img = pixel_to_math(y, 2, -2, HEIGHT) * fractal->zoom;
	is_julia(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = sum_complexe(carre_complexe(z), c);
		if ((z.real * z.real) + (z.img * z.img) > 4)
		{
			color = pixel_to_math(i, BLACK, 0x02050507, 256);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, 0x0);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, \
							fractal->img.img_ptr, 0, 0);
}
