/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:57:00 by mkhairou          #+#    #+#             */
/*   Updated: 2022/10/28 16:16:06 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_conv(va_list ptr, const char form)
{
	int	len;

	len = 0;
	if (form == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (form == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (form == 'p')
		len += ft_printf_ptr(va_arg(ptr, unsigned long int));
	else if (form == 'd' || form == 'i')
		len += ft_putnbr(va_arg(ptr, int));
	else if (form == 'u')
		len += ft_printf_unsi(va_arg(ptr, unsigned int));
	else if (form == 'x' || form == 'X')
		len += ft_printf_hex(va_arg(ptr, unsigned int), form);
	else if (form == '%')
		len += ft_printf_perc();
	return (len);
}

int	ft_printf(const char *a, ...)
{
	int		i;
	va_list	ptr;
	int		len;

	va_start (ptr, a);
	i = 0;
	len = 0;
	while (a[i])
	{
		if (a[i] == '%')
		{
			len += ft_conv(ptr, a[i + 1]);
			i++;
		}
		else
			len += ft_putchar(a[i]);
		i++;
	}
	va_end (ptr);
	return (len);
}
