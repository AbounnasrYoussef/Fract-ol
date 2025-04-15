/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:15:49 by yabounna          #+#    #+#             */
/*   Updated: 2025/03/15 15:14:00 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000

typedef struct s_complexe
{
	double	real;
	double	img;
}			t_complexe;
typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	char	*name;
	int		iterations;
	double	zoom;
	double	julia_r;
	double	julia_im;
	t_img	img;
}		t_fractal;

int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
int			ft_close_handler(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			ft_mouse_handler(int keycode, int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		is_julia(t_complexe *z, t_complexe *c, t_fractal *fractal);
void		draw_pixel(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			check_number(char *s);
void		ft_print_message(void);
void		check_entrer(int ac, char **av, t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		fractol_init(t_fractal *fractal);
double		pixel_to_math(double value, double new_min,
				double new_max, double old_max);
double		conv_double(char *s);
t_complexe	sum_complexe(t_complexe z1, t_complexe z2);
t_complexe	carre_complexe(t_complexe z);
#endif
