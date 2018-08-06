/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mandelbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:55:08 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:55:09 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int		get_color_m(int i, t_val *v)
{
	t_color			col;
	double			index;

	index = i + 1 + 6006 + v->g - (log(2) / (v->new_r * v->new_r +
	v->new_i * v->new_i)) / log(2);
	if (i == v->deep)
		return (0x000000);
	col.channel[0] = (unsigned char)(sin(0.016 * index + 4) * 180 + 75);
	col.channel[1] = (unsigned char)(sin(0.013 * index + 2) * 255 + 0);
	col.channel[2] = (unsigned char)(sin(0.01 * index + 1) * 255 + 0);
	col.channel[3] = 255;
	return (col.num);
}

double				mdb_real_part(t_val v)
{
	if (v.index == 3)
		return (v.ozr * v.ozr - v.ozi * v.ozi + v.zr);
	else if (v.index == 4)
		return (v.ozr * v.ozr * v.ozr - 3 * v.ozr * v.ozi * v.ozi + v.zr);
	else if (v.index == 5)
		return (v.ozr * v.ozr * v.ozr * v.ozr - 6 * v.ozr * v.ozr *
		v.ozi * v.ozi + v.ozi * v.ozi * v.ozi * v.ozi + v.zr);
	else if (v.index == 6)
		return (v.ozr * v.ozr * v.ozr * v.ozr * v.ozr -
		10 * v.ozr * v.ozr * v.ozr * v.ozi * v.ozi +
		5 * v.ozr * v.ozi * v.ozi * v.ozi * v.ozi + v.zr);
	else
		return (-1);
}

double				mdb_imagine_part(t_val v)
{
	if (v.index == 3)
		return (2 * v.ozr * v.ozi + v.zi);
	else if (v.index == 4)
		return (3 * v.ozr * v.ozr * v.ozi - (v.ozi * v.ozi * v.ozi) + v.zi);
	else if (v.index == 5)
		return (4 * v.ozr * v.ozr * v.ozr * v.ozi - 4 *
		(v.ozr * v.ozi * v.ozi * v.ozi) + v.zi);
	else if (v.index == 6)
		return (5 * v.ozr * v.ozr * v.ozr * v.ozr * v.ozi -
		10 * (v.ozr * v.ozr * v.ozi * v.ozi * v.ozi) +
		v.ozi * v.ozi * v.ozi * v.ozi * v.ozi + v.zi);
	else
		return (-1);
}

void				iterate_mdb(t_val *v)
{
	int				i;

	i = 0;
	while (i < v->deep)
	{
		v->ozr = v->new_r;
		v->ozi = v->new_i;
		v->new_r = mdb_real_part(*v);
		v->new_i = mdb_imagine_part(*v);
		if (v->new_r * v->new_r + v->new_i * v->new_i > 4)
			break ;
		i++;
	}
	put_pxl(v, v->x, v->y, get_color(i, v));
}

void				init_mbd(t_w *w)
{
	w->zoom = 1;
	w->itr = 1;
	w->deep = 300;
	w->fr->ci = 0;
	w->fr->cr = 0;
	if (w->index == 3)
		w->zoom = 1;
	if (w->index >= 4 && w->index <= 6)
		w->zoom = 1 - 0.2;
	w->g += (w->index - 3);
}
