/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_color_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:54:08 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:54:09 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			color_shift(int key, t_w *w)
{
	if (key == 13)
		w->g++;
	else if (key == 1)
		w->g--;
}

unsigned int	get_color(int i, t_val *v)
{
	if (v->index == 1)
		return (get_color_jul(i, v));
	else if (v->index == 7 || v->index == 8)
		return (get_color_jul(i, v));
	else if (v->index == 2)
		return (get_color_s(i, v));
	else if (v->index >= 3 && v->index <= 6)
		return (get_color_m(i, v));
	return (0);
}
