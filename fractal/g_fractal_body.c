/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_fractal_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:54:45 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/13 15:54:47 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_x(void)
{
	exit(1);
}

void	iterate(t_val *v)
{
	if (v->index == 1 || v->index == 7 || v->index == 8)
		iterate_julia(v);
	else if (v->index == 2)
		iterate_bns(v);
	else if (v->index >= 3 && v->index <= 6)
		iterate_mdb(v);
}

void	*pthreat_fract(void *val)
{
	t_val		*v;

	v = (t_val*)val;
	zr_zi_move(v);
	while (v->y < v->max)
	{
		v->x = 0;
		while (v->x < WIDTH)
		{
			v->zr = 1.5 * (v->x - WIDTH / 2) / (v->con1) +
			v->movex / 10000.0 + v->zr_m;
			v->zi = (v->y - HEIGHT / 2) / (v->con2) +
			v->movey / 10000.0 + v->zi_m;
			init_var(v);
			iterate(v);
			v->x++;
		}
		v->y++;
	}
	pthread_exit(NULL);
}

void	fractal_draw(t_w w)
{
	pthread_t	thread[TR];
	int			thr_id;
	int			i;
	t_val		v[TR];

	i = 0;
	mlx_clear_window(w.fr->mlx, w.fr->win);
	window_info(w);
	while (i < TR)
	{
		pthread_param(&v[i], w, i);
		thr_id = pthread_create(&thread[i], NULL, &pthreat_fract, &v[i]);
		pthreat_error(thr_id);
		i++;
	}
	i = 0;
	while (i < TR)
	{
		thr_id = pthread_join(thread[i], NULL);
		pthreat_error(thr_id);
		i++;
	}
	mlx_put_image_to_window(w.fr->mlx, w.fr->win, w.fr->img, 0, 0);
}

void	fractal_window(t_w w)
{
	(&w)->fr = fr_init();
	w.fr->mlx = mlx_init();
	w.fr->win = mlx_new_window(w.fr->mlx, WIDTH, HEIGHT + 200, "Fractol\
	(made by dkliukin)");
	w.fr->img = mlx_new_image(w.fr->mlx, WIDTH, HEIGHT);
	w.fr->data = mlx_get_data_addr(w.fr->img, &(w.fr->bpp),
	&(w.fr->sl), &(w.fr->ei));
	init_fract_param(&w);
	w.ms_zr = 0;
	w.ms_zi = 0;
	fractal_draw(w);
	mlx_hook(w.fr->win, 2, 5, key_hook, &w);
	mlx_mouse_hook(w.fr->win, mouse_zoom, &w);
	mlx_hook(w.fr->win, 17, 1L << 17, exit_x, NULL);
	mlx_hook(w.fr->win, 6, (1L << 6), mouse_track, &w);
	mlx_loop(w.fr->mlx);
}
