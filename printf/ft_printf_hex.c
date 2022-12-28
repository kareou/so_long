/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:36:45 by mkhairou          #+#    #+#             */
/*   Updated: 2022/10/28 15:05:07 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_hex(unsigned int nb, const char form)
{
	if (nb >= 16)
	{
		ft_hex(nb / 16, form);
		ft_hex(nb % 16, form);
	}
	else
	{
		if (nb <= 9)
			ft_printchar(nb + '0');
		else
		{
			if (form == 'x')
				ft_printchar((nb - 10) + 'a');
			if (form == 'X')
				ft_printchar((nb - 10) + 'A');
		}
	}
}

int	ft_printf_hex(unsigned int nb, const char form)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_hex(nb, form);
	return (len(nb));
}
