/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gere_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:30:10 by roddavid          #+#    #+#             */
/*   Updated: 2018/03/08 13:00:08 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int		ft_gere_hook(int key, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	if (key == 82)
		ft_activate_julia(data);
	if (key == 1)
		ft_switch_fractale(data);
	if (key == 67)
		ft_color1(key, data);
	if (key == 75)
		ft_color2(key, data);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (key == 69 || key == 78)
		ft_iteration(key, data);
	if (key == 15)
		ft_reset(data);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(key, data);
	ft_print(data);
	return (0);
}

int		ft_gere_mouse(int key, int x, int y, t_data *data)
{
	if (key == 1 || key == 2 || key == 4 || key == 5)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		data->y = 0;
		if (key == 1 || key == 4)
			f_zoom(key, x, y, data);
		if (key == 2 || key == 5)
			f_zoom(key, x, y, data);
	}
	ft_print(data);
	return (0);
}

int		ft_mouse_position(int x, int y, t_data *data)
{
	if (data->act == 1)
	{
		if (y > 0 && y < WIN_H && x > 0 && x < WIN_W)
			data->mouse_x = x;
		if (y > 0 && y < WIN_H && x > 0 && x < WIN_W)
			data->mouse_y = y;
	}
	ft_print(data);
	return (0);
}
