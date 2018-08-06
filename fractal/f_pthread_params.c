/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pthread_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:54:25 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:54:27 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pthreat_error(int id)
{
	if (id != 0)
	{
		ft_putendl("Error of pthread library");
		exit(0);
	}
}

void		pthread_param(t_val *v, t_w w, int i)
{
	v->ms_zr = w.ms_zr;
	v->cr = w.fr->cr;
	v->ci = w.fr->ci;
	v->ms_zi = w.ms_zi;
	v->index = w.index;
	v->movex = w.movex;
	v->movey = w.movey;
	v->zoom = w.zoom;
	v->deep = w.deep;
	v->data = (w.fr->data);
	v->min = i * HEIGHT / 4;
	v->max = (i + 1) * HEIGHT / 4;
	v->sl = w.fr->sl;
	v->g = w.g;
}
