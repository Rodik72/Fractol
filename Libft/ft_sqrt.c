/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:09:27 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/29 16:18:39 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = 2;
	if (nb == 1)
		return (1);
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i = i + 1;
	}
	return (0);
}