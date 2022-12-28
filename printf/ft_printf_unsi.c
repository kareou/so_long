/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:14:39 by mkhairou          #+#    #+#             */
/*   Updated: 2022/10/28 15:15:42 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	dec_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	ft_printf_unsi(unsigned int nb)
{
	if (nb < 10)
		ft_printchar(nb + '0');
	else
	{
		ft_printf_unsi(nb / 10);
		ft_printf_unsi(nb % 10);
	}
	return (dec_len(nb));
}
