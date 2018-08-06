/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_run_fractal_mdb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:53:31 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:53:33 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_run(t_w *w)
{
	w->index = 3;
	fractal_window(*w);
}

void	mandelbrot_run_3(t_w *w)
{
	w->index = 4;
	fractal_window(*w);
}

void	mandelbrot_run_4(t_w *w)
{
	w->index = 5;
	fractal_window(*w);
}

void	mandelbrot_run_5(t_w *w)
{
	w->index = 6;
	fractal_window(*w);
}
