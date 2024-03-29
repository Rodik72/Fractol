/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:52 by roddavid          #+#    #+#             */
/*   Updated: 2018/01/18 16:02:09 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut_free(char *s1, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s1[i] != c)
		i++;
	i++;
	tmp = ft_strdup(&(s1[i]));
	free(s1);
	return (tmp);
}
