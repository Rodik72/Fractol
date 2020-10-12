/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:05:01 by roddavid          #+#    #+#             */
/*   Updated: 2018/04/18 14:31:39 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	f_zoom2(t_data *data, int x, int y)
{
	data->mouse_sx = x;
	data->mouse_sy = y;
}

int		get_thread_id(pthread_t core_id, pthread_t *core)
{
	int		i;

	i = -1;
	while (++i < THREADS)
	{
		if (core[i] == core_id)
			return (i);
	}
	return (-1);
}
