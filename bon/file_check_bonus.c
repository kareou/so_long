/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:44:42 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 15:53:00 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_chr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while ((a[i] != '\0' && b[i] != '\0') && n > i)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	if (i < n)
		return (a[i] - b[i]);
	return (0);
}

char	ext_check(const char *a)
{
	char	*b;

	b = ft_chr(a, '.');
	if (!b || b == a)
	{
		ft_printf(RED "no .ber file\n" DEF);
		return (0);
	}
	b++;
	if (ft_strncmp(b, "ber", 3) != 0 || ft_strlen(b) != ft_strlen("ber"))
	{
		ft_printf(CYAN "no .ber file\n" DEF);
		return (0);
	}
	return (1);
}
