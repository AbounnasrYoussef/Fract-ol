/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:12:11 by yabounna          #+#    #+#             */
/*   Updated: 2025/03/10 22:25:27 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		ft_close_handler(fractal);
	mlx_clear_window(fractal->mlx, fractal->win);
	fractal_render(fractal);
	return (0);
}

int	ft_mouse_handler(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		fractal->zoom *= 1.1;
	else if (keycode == 5)
		fractal->zoom *= 0.9;
	mlx_clear_window(fractal->mlx, fractal->win);
	fractal_render(fractal);
	return (0);
}
