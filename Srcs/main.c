/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:12:15 by roddavid          #+#    #+#             */
/*   Updated: 2018/04/20 13:24:04 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void		ft_print(t_data *data)
{
	t_data	tab[THREADS];
	int		i;

	i = -1;
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	while (++i < THREADS)
	{
		if (data->id == 1)
			pthread_create(&data->core[i], NULL, ft_mandelbrot, &tab[i]);
		if (data->id == 2 || data->id == 6)
			pthread_create(&data->core[i], NULL, ft_julia, &tab[i]);
		if (data->id == 3)
			pthread_create(&data->core[i], NULL, ft_tricorn, &tab[i]);
		if (data->id == 4)
			pthread_create(&data->core[i], NULL, ft_egg, &tab[i]);
		if (data->id == 5)
			pthread_create(&data->core[i], NULL, ft_burning_ship, &tab[i]);
		tab[i] = *data;
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(data->core[i], NULL);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
}

void		ft_init_win(t_data *data)
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

void		ft_fractal(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Fractale");
	ft_init_win(data);
	ft_print(data);
	mlx_hook(data->mlx_win, 2, (1L << 0), ft_gere_hook, data);
	mlx_hook(data->mlx_win, 6, (1L << 6), ft_mouse_position, data);
	mlx_mouse_hook(data->mlx_win, ft_gere_mouse, data);
	mlx_loop(data->mlx_ptr);
}

int			ft_select_fractal(t_data *data, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		data->id = 1;
	else if (ft_strcmp(argv[1], "Julia") == 0)
		data->id = 2;
	else if (ft_strcmp(argv[1], "Tricorn") == 0)
		data->id = 3;
	else if (ft_strcmp(argv[1], "Egg") == 0)
		data->id = 4;
	else if (ft_strcmp(argv[1], "Burning_Ship") == 0)
		data->id = 5;
	else if (ft_strcmp(argv[1], "Necklace") == 0)
		data->id = 6;
	else
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
	{
		ft_putstr("usage : ./fractol	<Mandelbrot>\n\t\t\t<Julia>\n");
		ft_putendl("\t\t\t<Tricorn>\n\t\t\t<Egg>\n\t\t\t<Burning_Ship>");
		ft_putendl("\t\t\t<Necklace>");
		return (0);
	}
	if (ft_select_fractal(&data, argv) == 1)
	{
		ft_putstr("usage : ./fractol	<Mandelbrot>\n\t\t\t<Julia>\n");
		ft_putendl("\t\t\t<Tricorn>\n\t\t\t<Egg>\n\t\t\t<Burning_Ship>");
		ft_putendl("\t\t\t<Necklace>");
		return (0);
	}
	ft_fractal(&data);
	return (0);
}
