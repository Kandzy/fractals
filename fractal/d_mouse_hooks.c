/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_mouse_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:53:59 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:54:00 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

int		mouse_track(int x, int y, t_w *w)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT ||
	w->space_flag == OFF)
		return (0);
	w->fr->ci = -0.7 * (WIDTH / 2) / x;
	w->fr->cr = 0.27015 * (HEIGHT / 2) / y;
	fractal_draw(*w);
	return (0);
}

void	first_point(double *re, int x, t_w *w)
{
	*re = (1.5 * (x - WIDTH / 2) /
	(0.5 * w->zoom * WIDTH) + w->movex / 10000.0);
}

void	second_point(double *im, int y, t_w *w)
{
	*im = ((y - HEIGHT / 2) /
	(0.5 * w->zoom * HEIGHT) + w->movey / 10000.0);
}

int		mouse_zoom(int button, int x, int y, t_w *w)
{
	if (button == 5 && x < WIDTH && y < HEIGHT
	&& x > 0 && y > 0)
	{
		zoom_out(x, y, w);
	}
	if (button == 4 && x < WIDTH && y < HEIGHT
	&& x > 0 && y > 0)
	{
		zoom_in(x, y, w);
	}
	if ((button == 4 || button == 5) && x < WIDTH && y < HEIGHT
	&& x > 0 && y > 0)
		fractal_draw(*w);
	return (0);
}
