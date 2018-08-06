/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_zoom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:54:14 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:54:15 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_fract_out(t_w *w)
{
	if (w->itr - 1 > 0)
	{
		if ((w->index == 1 || w->index == 7 || w->index == 8) && w->deep > 20)
		{
			if (w->deep < 350)
				w->deep -= 1;
			else if ((int)(w->itr) % 16 == 0)
				w->deep -= 1;
		}
		if (w->index == 2 && w->deep > 20)
			w->deep -= 2;
		if (w->index >= 3 && w->index <= 6 && w->deep > 20)
			w->deep -= 3;
		w->itr--;
		w->zoom -= 0.001 * (w->itr * w->itr * w->itr);
	}
}

void	zoom_fract_in(t_w *w)
{
	w->zoom += 0.001 * (w->itr * w->itr * w->itr);
	w->itr++;
	if ((w->index == 1 || w->index == 7 || w->index == 8) && w->deep < 9900)
	{
		if (w->deep < 350)
			w->deep += 1;
		else if ((int)(w->itr) % 16 == 0)
			w->deep += 1;
	}
	if (w->index == 2 && w->deep < 9900)
		w->deep += 2;
	if (w->index >= 3 && w->index <= 6 && w->deep < 9900)
		w->deep += 3;
}

void	zoom_out(int x, int y, t_w *w)
{
	double	mouse_re_2;
	double	mouse_im_2;
	double	mouse_re_1;
	double	mouse_im_1;

	first_point(&mouse_re_1, x, w);
	second_point(&mouse_im_1, y, w);
	zoom_fract_out(w);
	first_point(&mouse_re_2, x, w);
	second_point(&mouse_im_2, y, w);
	w->movex -= (mouse_re_2 - mouse_re_1) * 10000;
	w->movey -= (mouse_im_2 - mouse_im_1) * 10000;
}

void	zoom_in(int x, int y, t_w *w)
{
	double	mouse_re_2;
	double	mouse_im_2;
	double	mouse_re_1;
	double	mouse_im_1;

	first_point(&mouse_re_1, x, w);
	second_point(&mouse_im_1, y, w);
	zoom_fract_in(w);
	first_point(&mouse_re_2, x, w);
	second_point(&mouse_im_2, y, w);
	w->movex += (mouse_re_1 - mouse_re_2) * 10000;
	w->movey += (mouse_im_1 - mouse_im_2) * 10000;
}
