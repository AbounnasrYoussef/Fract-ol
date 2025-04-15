/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:01:05 by yabounna          #+#    #+#             */
/*   Updated: 2025/03/15 15:08:19 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_number(char *s)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] != '.' && (s[i] < '0' || s[i] > '9'))
			return (1);
		if (s[i] == '.')
			point++;
		i++;
	}
	if (point > 1)
		return (1);
	return (0);
}

void	ft_print_message(void)
{
	ft_putstr_fd("usage:\n\t./fractol mandelbrot\n", 2);
	ft_putstr_fd("\t./fractol julia <r> <im> (between -2 and 2)\n", 2);
	exit(EXIT_FAILURE);
}

void	check_entrer(int ac, char **av, t_fractal *fractal)
{
	if (ac <= 1)
		ft_print_message();
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		fractal->name = av[1];
		return ;
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia") \
			&& !check_number(av[2]) && !check_number(av[3]))
	{
		fractal->name = av[1];
		fractal->julia_r = conv_double(av[2]);
		fractal->julia_im = conv_double(av[3]);
		if (conv_double(av[2]) > 2 || conv_double(av[2]) < -2
			|| conv_double(av[3]) > 2 || conv_double(av[3]) < -2)
			(ft_putstr_fd("Invalid coords\n", 2), exit(1));
	}
	else
		ft_print_message();
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	check_entrer(ac, av, &fractal);
	fractol_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
