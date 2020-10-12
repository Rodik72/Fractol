/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:29:16 by roddavid          #+#    #+#             */
/*   Updated: 2018/04/19 17:01:51 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"
#define ZI data->z_i
#define ZR data->z_r

void	ft_pixel_burning_ship(t_data *data)
{
	if (data->i < data->imax)
		mlx_pixel_put_to_image(data->mlx_img, data->x, data->y, \
				((data->i * 0xFF / data->imax) << data->color2) + \
				((data->i * 0xFF / data->imax) << data->color));
	if (data->i < data->imax / 2)
		mlx_pixel_put_to_image(data->mlx_img, data->x, data->y, \
				((data->i * 0xFF / data->imax) << data->color2));
}

void	ft_calc_burning_ship(t_data *data, int thread_id, int padding)
{
	while (data->y < WIN_H)
	{
		data->x = thread_id * padding;
		while (data->x < ((thread_id + 1) * padding))
		{
			data->c_r = data->x / data->zoom + data->x1;
			data->c_i = data->y / data->zoom + data->y1;
			ZR = 0;
			ZI = 0;
			data->i = 0;
			while (((ZR * ZR) + (ZI * ZI) < 4) && data->i < data->imax)
			{
				data->tmp = ZR;
				ZR = fabs((ZR * ZR) - (ZI * ZI) + data->c_r);
				ZI = fabs(2 * ZI * data->tmp + data->c_i);
				data->i++;
			}
			ft_pixel_burning_ship(data);
			data->x++;
		}
		data->y++;
	}
}

void	*ft_burning_ship(void *param)
{
	t_data	*data;
	int		padding;
	int		thread_id;

	data = (t_data *)param;
	padding = WIN_W / THREADS;
	data->y = 0;
	thread_id = get_thread_id(pthread_self(), data->core);
	ft_calc_burning_ship(data, thread_id, padding);
	pthread_exit(NULL);
	return (NULL);
}
