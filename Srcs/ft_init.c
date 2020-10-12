/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:25:59 by roddavid          #+#    #+#             */
/*   Updated: 2018/04/20 13:45:17 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_init_mandelbrot(t_data *data)
{
	data->act = 0;
	data->mouse_sx = 0;
	data->mouse_sx = 0;
	data->color = 8;
	data->color2 = 16;
	data->c_r = 0;
	data->c_i = 0;
	data->zoom = 250;
	data->x_img = (data->x2 - data->x1) * data->zoom;
	data->y_img = (data->y2 - data->y1) * data->zoom;
	data->imax = 50;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
}

void	ft_init_julia(t_data *data)
{
	data->act = 0;
	data->mouse_sx = 0;
	data->mouse_sy = 0;
	data->color = 8;
	data->color2 = 16;
	data->zoom = 250;
	data->x_img = (data->x2 - data->x1) * data->zoom;
	data->y_img = (data->y2 - data->y1) * data->zoom;
	data->x1 = -1.4;
	data->x2 = 1;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->imax = 150;
	if (data->id == 6)
	{
		data->color = 10;
		data->color2 = 18;
		data->x1 = -1.7;
		data->y1 = -1.5;
		data->zoom = 200;
		data->c_r = -1;
	}
}

void	ft_init_tricorn(t_data *data)
{
	data->act = 0;
	data->mouse_sx = 0;
	data->mouse_sy = 0;
	data->color = 8;
	data->color2 = 16;
	data->c_r = 0;
	data->c_i = 0;
	data->x_img = (data->x2 - data->x1) * data->zoom;
	data->y_img = (data->y2 - data->y1) * data->zoom;
	data->imax = 50;
	data->zoom = 180;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.6;
	data->y2 = 1.2;
}

void	ft_init_egg(t_data *data)
{
	data->act = 0;
	data->mouse_sx = 0;
	data->mouse_sy = 0;
	data->color = 8;
	data->color2 = 16;
	data->c_r = 0;
	data->c_i = 0;
	data->zoom = 250;
	data->x_img = (data->x2 - data->x1) * data->zoom;
	data->y_img = (data->y2 - data->y1) * data->zoom;
	data->x1 = -1.4;
	data->x2 = 1;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->imax = 150;
}

void	ft_init_burning_ship(t_data *data)
{
	data->act = 0;
	data->mouse_sx = 0;
	data->mouse_sx = 0;
	data->color = 8;
	data->color2 = 16;
	data->c_r = 0;
	data->c_i = 0;
	data->zoom = 180;
	data->x_img = (data->x2 - data->x1) * data->zoom;
	data->y_img = (data->y2 - data->y1) * data->zoom;
	data->imax = 50;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -2;
	data->y2 = 1.2;
}
