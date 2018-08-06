/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_burningship.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:54:39 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:54:41 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color_s(int i, t_val *v)
{
	t_color		col;
	double		index;

	index = i + 1 + 7462 + v->g - (log(2) / (v->ozr * v->ozr +
	v->ozi * v->ozi)) / log(2);
	if (i == v->deep)
		return (0x000000);
	col.channel[0] = (unsigned char)(sin(0.016 * index + 4) * 230 + 25);
	col.channel[1] = (unsigned char)(sin(0.013 * index + 2) * 230 + 25);
	col.channel[2] = (unsigned char)(sin(0.01 * index + 1) * 230 + 25);
	col.channel[3] = 255;
	return (col.num);
}

void			iterate_bns(t_val *v)
{
	int			i;

	i = 0;
	while (i < v->deep)
	{
		v->b_temp = v->ozr;
		v->ozr = v->ozr * v->ozr - v->ozi * v->ozi + v->zr;
		v->ozi = 2 * ABS(v->ozi * v->b_temp) + v->zi;
		if (v->ozr * v->ozr + v->ozi * v->ozi > 4)
			break ;
		i++;
	}
	put_pxl(v, v->x, v->y, get_color(i, v));
}

void			init_bns(t_w *w)
{
	w->fr->ci = 0;
	w->fr->cr = 0;
	w->zoom = 18;
	w->itr = 1;
	w->deep = 230;
}

void			burningship_run(t_w *w)
{
	w->index = 2;
	fractal_window(*w);
}
