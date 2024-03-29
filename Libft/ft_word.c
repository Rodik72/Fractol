/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:43:31 by roddavid          #+#    #+#             */
/*   Updated: 2017/11/16 16:54:39 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i] != c)
		count++;
	while (s[i])
	{
		if (i > 0 && (s[i - 1] == c && s[i] != c))
			count++;
		i++;
	}
	return (count);
}
