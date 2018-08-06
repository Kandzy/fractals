/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_run_fractal_julia.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:53:23 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:53:24 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_run(t_w *w)
{
	w->index = 1;
	fractal_window(*w);
}

void	julia_run_3(t_w *w)
{
	w->index = 7;
	fractal_window(*w);
}

void	julia_run_4(t_w *w)
{
	w->index = 8;
	fractal_window(*w);
}
