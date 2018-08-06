/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_initiate_fractal_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:53:42 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:53:43 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*fr_init(void)
{
	t_fractal *fr;

	fr = (t_fractal*)ft_memalloc(sizeof(t_fractal));
	return (fr);
}

void		zr_zi_move(t_val *v)
{
	v->y = v->min;
	v->con1 = 0.5 * v->zoom * WIDTH;
	v->con2 = 0.5 * v->zoom * HEIGHT;
	if (v->index == 1 || v->index == 7 || v->index == 8)
	{
		v->zr_m = 0;
		v->zi_m = 0;
	}
	else if (v->index == 3)
	{
		v->zr_m = -0.5;
		v->zi_m = 0;
	}
	else if (v->index == 2)
	{
		v->zr_m = -1.75;
		v->zi_m = -0.025;
	}
	else if (v->index >= 4 || v->index <= 6)
	{
		v->zr_m = 0;
		v->zi_m = 0;
	}
}

void		init_var(t_val *v)
{
	if (v->index == 1)
	{
		v->ozr = 0;
		v->ozi = 0;
	}
	if (v->index == 2)
	{
		v->ozr = 0;
		v->ozi = 0;
	}
	if (v->index >= 3 && v->index <= 6)
	{
		v->new_i = 0;
		v->new_r = 0;
		v->ozr = 0;
		v->ozi = 0;
	}
}

void		init_fract_param(t_w *w)
{
	w->g = 0;
	w->movey = 0;
	w->movex = 0;
	if (w->index == 1 || w->index == 7 || w->index == 8)
		init_julia(w);
	else if (w->index == 2)
		init_bns(w);
	else if (w->index >= 3 & w->index <= 6)
		init_mbd(w);
}
