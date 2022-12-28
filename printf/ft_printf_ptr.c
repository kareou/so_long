/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:13:50 by mkhairou          #+#    #+#             */
/*   Updated: 2022/10/28 15:13:28 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	hex_len(unsigned long long nb)
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

void	ft_hexptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_hexptr(nb / 16);
		ft_hexptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_printchar(nb + '0');
		else
			ft_printchar((nb % 10) + 'a');
	}
}

int	ft_printf_ptr(unsigned long long nb)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		ft_hexptr(nb);
		len += hex_len(nb);
	}
	return (len);
}
