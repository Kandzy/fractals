/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_key_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:53:52 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:53:54 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		new_window(int key, t_w w)
{
	if (key >= 83 && key <= 89)
		w.index = key - 82;
	else if (key == 91)
		w.index = 8;
	if ((key >= 83 && key <= 89) || key == 91)
	{
		w.space_flag = OFF;
		fractal_window(w);
	}
}

void		any_fractal(int key, t_w *w)
{
	int		w_index;

	w_index = w->index;
	if (key >= 18 && key <= 21)
		w->index = key - 17;
	else if (key == 23)
		w->index = 5;
	else if (key == 22)
		w->index = 6;
	else if (key == 26)
		w->index = 7;
	else if (key == 28)
		w->index = 8;
	if (key == 48)
	{
		if (w->index < 9)
			w->index++;
		if (w->index == 9)
			w->index = 1;
	}
	if (w_index != w->index)
	{
		w->space_flag = OFF;
		init_fract_param(w);
	}
}

void		move_fractal(int key, t_w *w)
{
	if (key == 125)
		w->movey += 200.0 / (w->itr * sqrt(w->zoom));
	else if (key == 126)
		w->movey -= 200.0 / (w->itr * sqrt(w->zoom));
	else if (key == 123)
		w->movex -= 200.0 / (w->itr * sqrt(w->zoom));
	else if (key == 124)
		w->movex += 200.0 / (w->itr * sqrt(w->zoom));
}

int			if_true_false(int key)
{
	if (key == 124 || key == 123 || key == 126 || key == 125 || key == 78 ||
	key == 69 || key == 13 || key == 1 || key == 51 || key == 48 || (key >=
	18 && key <= 23) || key == 26 || key == 28 || key == 27 || key == 24)
		return (1);
	else
		return (0);
}

int			key_hook(int key, t_w *w)
{
	move_fractal(key, w);
	color_shift(key, w);
	any_fractal(key, w);
	new_window(key, *w);
	if (key == 27 && w->deep > 20)
		w->deep -= 10;
	if (key == 24 && w->deep < 9900)
		w->deep += 10;
	if (key == 78)
		zoom_fract_out(w);
	if (key == 69)
		zoom_fract_in(w);
	if (key == 51)
		init_fract_param(w);
	if (key == 49 && w->space_flag == OFF)
		w->space_flag = ON;
	else if (key == 49 && w->space_flag == ON)
		w->space_flag = OFF;
	if (if_true_false(key))
		fractal_draw(*w);
	if (key == 53)
		exit(0);
	return (0);
}
