/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:49 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/26 13:40:06 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (n)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	int	*pt;

	pt = (void *)malloc(count * size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, count * size);
	return (pt);
}
