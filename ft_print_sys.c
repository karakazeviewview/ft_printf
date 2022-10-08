/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:42:16 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/06/15 21:53:36 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert_2(va_list agp, char c, int *len)
{
	if (c == 'd' || c == 'i')
		(*len) = (*len) + ft_putnbr_fd(va_arg(agp, int), 1);
	else if (c == 'u')
		(*len) = (*len) + ft_itosu(va_arg(agp, size_t));
	else if (c == 'x')
		(*len) = (*len) + ft_put_sx(va_arg(agp, size_t));
	else if (c == 'X')
		(*len) = (*len) + ft_put_slx(va_arg(agp, size_t));
	else if (c == '%')
	{
		write(1, "%", 1);
		(*len) = (*len) + 1;
	}
	else
		return (0);
	return (1);
}

size_t	ft_convert(va_list agp, char c, int *len)
{
	size_t	i;

	if (c == 'c')
	{
		ft_putchar_fd((char)(va_arg(agp, size_t)), 1);
		(*len)++;
	}
	else if (c == 's')
		(*len) = (*len) + ft_string(va_arg(agp, char *));
	else if (c == 'p')
	{
		i = va_arg(agp, size_t);
		write(1, "0x", 2);
		ft_itosx(i);
		(*len) = (*len) + ft_numlen16(i) + 2;
	}
	ft_convert_2(agp, c, len);
	return (1);
}
