/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:32:14 by yabounna          #+#    #+#             */
/*   Updated: 2025/03/15 15:10:04 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pixel_to_math(double value, double new_min,
			double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (value - old_min) \
			/ (old_max - old_min) + new_min);
}

t_complexe	sum_complexe(t_complexe z1, t_complexe z2)
{
	t_complexe	res;

	res.real = z1.real + z2.real;
	res.img = z1.img + z2.img;
	return (res);
}

t_complexe	carre_complexe(t_complexe z)
{
	t_complexe	res;

	res.real = (z.real * z.real) - (z.img * z.img);
	res.img = 2 * z.real * z.img;
	return (res);
}
