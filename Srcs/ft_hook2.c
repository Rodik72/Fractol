/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:49:08 by roddavid          #+#    #+#             */
/*   Updated: 2018/04/20 13:31:50 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void		ft_color2(int key, t_data *data)
{
	if (key == 75)
	{
		if (data->color > 0 && data->color2 > 0 && data->color <= 20 \
			&& data->color2 <= 20)
		{
			data->color--;
			data->color2--;
		}
		else if (data->color == 0)
		{
			data->color = 12;
			data->color2 = 20;
		}
	}
}

void		ft_activate_julia(t_data *data)
{
	if (data->act == 0)
		data->act = 1;
	else if (data->act == 1)
	{
		data->c_r = data->mouse_x / data->zoom + data->x1;
		data->c_i = data->mouse_y / data->zoom + data->y1;
		data->act = 0;
	}
}

void		ft_switch_fractale(t_data *data)
{
	if (data->id == 2)
		data->id = 3;
	else if (data->id == 1)
		data->id = 2;
	else if (data->id == 3)
		data->id = 4;
	else if (data->id == 4)
		data->id = 5;
	else if (data->id == 5)
		data->id = 6;
	else if (data->id == 6)
		data->id = 1;
	ft_init_win(data);
}
