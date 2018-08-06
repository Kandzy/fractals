/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:54:58 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:54:59 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int		get_color_jul(int i, t_val *v)
{
	t_color			col;
	double			index;

	index = i + 1 + 0 + v->g - (log(2) / (v->zr * v->zr +
	v->zi * v->zi)) / log(2);
	if (i == v->deep)
		return (0x000000);
	col.channel[0] = (unsigned char)(sin(0.016 * index + 4) * 230 + 25);
	col.channel[1] = (unsigned char)(sin(0.013 * index + 2) * 230 + 25);
	col.channel[2] = (unsigned char)(sin(0.01 * index + 1) * 230 + 25);
	col.channel[3] = 255;
	return (col.num);
}

double				julia_real_part(t_val v)
{
	if (v.index == 1)
		return (v.zr * v.zr - v.zi * v.zi);
	else if (v.index == 7)
		return (0.18 + v.zr * v.zr * v.zr - 3 * v.zr * v.zi * v.zi);
	else if (v.index == 8)
		return (-0.0655 + v.ozr * v.ozr * v.ozr * v.ozr - 6 * v.ozr * v.ozr *
		v.ozi * v.ozi + v.ozi * v.ozi * v.ozi * v.ozi);
	else
		return (-1);
}

double				julia_imagine_part(t_val v)
{
	if (v.index == 1)
		return (2 * v.ozr * v.ozi);
	else if (v.index == 7)
		return (-0.9 + 3 * v.ozr * v.ozr * v.ozi - (v.ozi * v.ozi * v.ozi));
	else if (v.index == 8)
		return (-0.11 + 4 * v.ozr * v.ozr * v.ozr * v.ozi - 4 *
		(v.ozr * v.ozi * v.ozi * v.ozi));
	else
		return (-1);
}

void				iterate_julia(t_val *v)
{
	int				i;

	i = 0;
	while (i < v->deep)
	{
		v->ozr = v->zr;
		v->ozi = v->zi;
		v->zr = julia_real_part(*v) + v->ci;
		v->zi = julia_imagine_part(*v) + v->cr;
		if (v->zr * v->zr + v->zi * v->zi > 4)
			break ;
		i++;
	}
	put_pxl(v, v->x, v->y, get_color(i, v));
}

void				init_julia(t_w *w)
{
	w->itr = 1;
	w->fr->ci = -0.7;
	w->fr->cr = 0.27015;
	if (w->index == 1)
	{
		w->zoom = 1;
		w->deep = 215;
	}
	if (w->index == 7)
	{
		w->zoom = 1;
		w->deep = 215;
	}
	if (w->index == 8)
	{
		w->zoom = 1 - 0.2;
		w->deep = 215;
	}
}
