/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 17:04:09 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/24 17:04:15 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft/includes/libft.h"
# include "math.h"
# include <pthread.h>
# include "time.h"
# define WIDTH 600
# define HEIGHT 500
# define TR 4
# define ON 1
# define OFF 0

/*
** Struct used for save params of fractol for
** threads
*/

typedef struct		s_value
{
	int					index;
	double				zr_m;
	double				zi_m;
	int					max;
	int					min;
	double				zr;
	double				zi;
	double				ozi;
	double				ozr;
	double				new_r;
	double				new_i;
	long double			zoom;
	double				movex;
	double				movey;
	int					sl;
	char				*data;
	int					deep;
	double				con1;
	double				con2;
	int					g;
	double				x;
	double				y;
	double				ms_zr;
	double				ms_zi;
	double				b_temp;
	double				ci;
	double				cr;
}					t_val;

/*
** Struct that keep params of fractals window
*/

typedef struct		s_fractal
{
	void				*mlx;
	void				*win;
	void				*img;
	double				zr;
	double				zi;
	double				cr;
	double				ci;
	char				*data;
	int					sl;
	int					bpp;
	int					ei;
}					t_fractal;

/*
** Struct that keep all info about fract settings and
** keep all changes that we do by hooks
*/

typedef struct		s_w
{
	int					index;
	void				(*fract)();
	struct s_fractal	*fr;
	long double			zoom;
	double				movex;
	double				movey;
	double				itr;
	int					deep;
	int					g;
	unsigned long long	imax;
	double				ms_zr;
	double				ms_zi;
	int					space_flag;
}					t_w;

/*
** Union that used for
*/

typedef union		u_color
{
	unsigned int	num;
	unsigned char	channel[4];
}					t_color;

/*
**run fractol index
*/

void				julia_run(t_w *w);
void				julia_run_3(t_w *w);
void				julia_run_4(t_w *w);
void				mandelbrot_run(t_w *w);
void				mandelbrot_run_3(t_w *w);
void				mandelbrot_run_4(t_w *w);
void				mandelbrot_run_5(t_w *w);
void				burningship_run(t_w *w);
int					run_error(t_w *w);

/*
**fractal settings
*/

void				iterate(t_val *v);
void				iterate_mdb(t_val *v);
void				iterate_julia(t_val *v);
void				iterate_bns(t_val *v);
void				init_fract_param(t_w *w);
void				zr_zi_move(t_val *v);

/*
**initiate fractal settings
*/

t_fractal			*fr_init();
void				init_var(t_val *v);
void				init_fract_param(t_w *w);
void				init_julia(t_w *w);
void				init_mbd(t_w *w);
void				init_bns(t_w *w);
void				pthread_param(t_val *v, t_w w, int i);
void				pthreat_error(int id);

/*
**main body of fractol
*/

void				window_info(t_w w);
void				window_info_mouse(t_w w);
void				fractal_window(t_w w);
void				fractal_draw(t_w w);
void				*pthreat_fract(void *val);
int					exit_x(void);

/*
**real and imagine part of fractals
*/

double				julia_real_part(t_val v);
double				julia_imagine_part(t_val v);
double				mdb_real_part(t_val v);
double				mdb_imagine_part(t_val v);

/*
**pixel manipulations (pix color)
*/

void				put_pxl(t_val *f, int x, int y, unsigned int c);
unsigned int		get_color(int i, t_val *v);
unsigned int		get_color_jul(int i, t_val *v);
unsigned int		get_color_m(int i, t_val *v);
unsigned int		get_color_s(int i, t_val *v);

/*
**key hooks + zoom in and zoom out
*/

int					key_hook(int key, t_w *w);
void				zoom_fract_out(t_w *w);
void				zoom_fract_in(t_w *w);
void				color_shift(int key, t_w *w);
int					if_true_false(int key);
void				move_fractal(int key, t_w *w);
void				any_fractal(int key, t_w *w);
void				new_window(int key, t_w w);

/*
**mouse hooks
*/

int					mouse_zoom(int button, int x, int y, t_w *w);
void				zoom_in(int x, int y, t_w *w);
void				zoom_out(int x, int y, t_w *w);
int					mouse_track(int x, int y, t_w *w);

/*
**Points for correct mouse zoom
*/

void				second_point(double *im, int y, t_w *w);
void				first_point(double *re, int x, t_w *w);

#endif
