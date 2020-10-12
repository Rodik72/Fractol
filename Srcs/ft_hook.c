/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:39:23 by roddavid          #+#    #+#             */
/*   Updated: 2018/04/20 13:31:29 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"
#define MSX data->mouse_sx
#define MSY data->mouse_sy

void		ft_color1(int key, t_data *data)
{
	if (key == 67)
	{
		if (data->color >= 0 && data->color2 >= 0 && data->color < 20 \
			&& data->color2 < 20)
		{
			data->color++;
			data->color2++;
		}
		else if (data->color2 == 20)
		{
			data->color = 0;
			data->color2 = 8;
		}
	}
}

void		f_zoom(int key, int x, int y, t_data *data)
{
	if ((MSX == x && MSY == y) && (key == 1 || key == 4))
	{
		data->x1 += (((WIN_W / 1.68) - (WIN_W / 2)) / data->zoom);
		data->y1 += (((WIN_H / 1.68) - (WIN_H / 2)) / data->zoom);
		data->zoom *= 1.2;
	}
	else if ((MSX == x && MSY == y) && (key == 2 || key == 5))
	{
		data->x1 += (((WIN_W / 2.68) - (WIN_W / 2)) / data->zoom);
		data->y1 += (((WIN_H / 2.68) - (WIN_H / 2)) / data->zoom);
		data->zoom *= 0.8;
	}
	else if (key == 1 || key == 4)
	{
		data->x1 += ((x - (WIN_W / 2.1)) / data->zoom);
		data->y1 += ((y - (WIN_H / 2.1)) / data->zoom);
		data->zoom *= 1.2;
	}
	else if (key == 2 || key == 5)
	{
		data->x1 += ((x - (WIN_W / 1.7)) / data->zoom);
		data->y1 += ((y - (WIN_H / 1.7)) / data->zoom);
		data->zoom *= 0.8;
	}
	f_zoom2(data, x, y);
}

void		ft_iteration(int key, t_data *data)
{
	if (key == 69)
	{
		if (data->imax < 500)
			data->imax += 2;
	}
	else if (key == 78)
	{
		if (data->imax > 3)
			data->imax -= 2;
	}
}

void		ft_move(int keycode, t_data *data)
{
	int speed;

	speed = 200;
	if (data->zoom > 1500)
		speed = 5;
	else if (data->zoom > 1000)
		speed = 30;
	else if (data->zoom > 750)
		speed = 80;
	else if (data->zoom > 500)
		speed = 100;
	if (keycode == 123)
		data->x1 += ((WIN_W / speed) / data->zoom);
	if (keycode == 124)
		data->x1 -= ((WIN_W / speed) / data->zoom);
	if (keycode == 125)
		data->y1 -= ((WIN_H / speed) / data->zoom);
	if (keycode == 126)
		data->y1 += ((WIN_H / speed) / data->zoom);
}

void		ft_reset(t_data *data)
{
	if (data->id == 1)
		ft_init_mandelbrot(data);
	if (data->id == 2 || data->id == 6)
		ft_init_julia(data);
	if (data->id == 3)
		ft_init_tricorn(data);
	if (data->id == 4)
		ft_init_egg(data);
	if (data->id == 5)
		ft_init_burning_ship(data);
}
