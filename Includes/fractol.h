/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:31:26 by roddavid          #+#    #+#             */
/*   Updated: 2018/04/20 13:35:50 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include "mlx.h"
# include "../Libft/libft.h"

# define WIN_W 675
# define WIN_H 600
# define THREADS 8
# define BUFF_SIZE 256

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	int				i;
	int				ithread;
	int				imax;
	int				init;
	int				id;
	int				color;
	int				color2;
	int				act;
	long double		x;
	long double		y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			x_img;
	double			y_img;
	double			c_r;
	double			z_r;
	double			c_i;
	double			z_i;
	double			mouse_y;
	double			mouse_x;
	double			mouse_sx;
	double			mouse_sy;
	double			zoom;
	double			tmp;
	pthread_t		core[THREADS];
}					t_data;

int					main(int argc, char **argv);
void				*ft_mandelbrot(void *param);
void				*ft_julia(void *param);
void				*ft_tricorn(void *param);
void				*ft_egg(void *param);
void				*ft_burning_ship(void *param);
void				mlx_pixel_put_to_image(void *img, int x, int y, int color);
int					get_thread_id(pthread_t core_id, pthread_t *core);
int					ft_gere_mouse(int key, int x, int y, t_data *data);
void				f_zoom(int key, int x, int y, t_data *data);
void				f_zoom2(t_data *data, int x, int y);
void				ft_init_mandelbrot(t_data *data);
void				ft_init_julia(t_data *data);
void				ft_init_tricorn(t_data *data);
void				ft_init_egg(t_data *data);
void				ft_init_burning_ship(t_data *data);
void				ft_print(t_data *data);
void				ft_iteration(int key, t_data *data);
int					ft_gere_hook(int key, t_data *data);
int					ft_mouse_position(int x, int y, t_data *data);
void				ft_reset(t_data *data);
void				ft_move(int keycode, t_data *data);
void				ft_color1(int key, t_data *data);
void				ft_color2(int key, t_data *data);
void				ft_switch_fractale(t_data *data);
void				ft_init_win(t_data *data);
void				ft_activate_julia(t_data *data);

#endif
