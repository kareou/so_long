/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:00:34 by mkhairou          #+#    #+#             */
/*   Updated: 2022/10/28 15:34:22 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_printchar(char a);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_printf_perc(void);
int		ft_printf_hex(unsigned int nb, const char form);
int		ft_putnbr(int nb);
int		ft_printf_ptr(unsigned long long nb);
int		ft_printf_unsi(unsigned int nb);
int		ft_printf(const char *a, ...);

#endif
