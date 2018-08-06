/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_fractol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:53:08 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:53:10 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		window_info(t_w w)
{
	char	*str;

	str = ft_itoa((int)(w.deep));
	mlx_string_put(w.fr->mlx, w.fr->win, 10, HEIGHT, 0xFFFFFF, "Press: 1) \
	arrows left/right/up/down - move fractal\t");
	mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 15, 0xFFFFFF, "      \
	2) \"NUM +/-\" - zooming");
	mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 30, 0xFFFFFF, "      \
	3) \"W/S\" - color shifting");
	mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 45, 0xFFFFFF, "      \
	4) \"1/2/3/4/5/6/7/8 or TAB\" - choose fractal");
	mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 60, 0xFFFFFF, "      \
	5) \"NUM 1/2/3/4/5/6/7/8\" - new window");
	mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 75, 0xFFFFFF, "      \
	6) \"BACKSPACE\" - reset parameters");
	mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 90, 0xFFFFFF, "      \
	7) \"+/-\" - depth level");
	window_info_mouse(w);
	mlx_string_put(w.fr->mlx, w.fr->win, 500, HEIGHT + 180, 0xFFFFFF, "Depth:");
	mlx_string_put(w.fr->mlx, w.fr->win, 560, HEIGHT + 180, 0xFFFFFF, str);
	mlx_string_put(w.fr->mlx, w.fr->win, 0, HEIGHT + 180, 0xFFFFFF, "\
	(ESC) - EXIT");
	ft_strdel(&str);
}

void		window_info_mouse(t_w w)
{
	mlx_string_put(w.fr->mlx, w.fr->win, 10, HEIGHT + 105, 0xFFFFFF, "Mouse:");
	mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 120, 0xFFFFFF, "      \
	1) \"Scroll UP/DOWN\" - zooming");
	if (w.index == 1 || w.index == 7 || w.index == 8)
	{
		mlx_string_put(w.fr->mlx, w.fr->win, 20, HEIGHT + 135,
		0xFFFFFF, "      \
		2) \"SPACE + MOVE MOUSE\" - change julia constants");
	}
}

void		put_pxl(t_val *f, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * f->sl);
	f->data[i] = c;
	f->data[++i] = c >> 8;
	f->data[++i] = c >> 16;
}

int			run_error(t_w *w)
{
	w->index = 0;
	ft_putendl("Avalible parameters:");
	ft_putendl("\t\t\t1. julia");
	ft_putendl("\t\t\t2. burningship");
	ft_putendl("\t\t\t3. mandelbrot");
	ft_putendl("\t\t\t4. mandelbrot_3");
	ft_putendl("\t\t\t5. mandelbrot_4");
	ft_putendl("\t\t\t6. mandelbrot_5");
	ft_putendl("\t\t\t7. julia_3");
	ft_putendl("\t\t\t8. julia_4");
	return (0);
}

int			main(int ac, char **av)
{
	t_w		w;

	w.space_flag = 0;
	if (ac == 2)
	{
		if (!(ft_strcmp(av[1], "julia")))
			julia_run(&w);
		else if (!(ft_strcmp(av[1], "julia_3")))
			julia_run_3(&w);
		else if (!(ft_strcmp(av[1], "julia_4")))
			julia_run_4(&w);
		else if (!(ft_strcmp(av[1], "mandelbrot")))
			mandelbrot_run(&w);
		else if (!(ft_strcmp(av[1], "mandelbrot_3")))
			mandelbrot_run_3(&w);
		else if (!(ft_strcmp(av[1], "mandelbrot_4")))
			mandelbrot_run_4(&w);
		else if (!(ft_strcmp(av[1], "mandelbrot_5")))
			mandelbrot_run_5(&w);
		else if (!(ft_strcmp(av[1], "burningship")))
			burningship_run(&w);
	}
	return (run_error(&w));
}
