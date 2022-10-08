/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_sys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:15 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/06/15 21:53:12 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_itosu(unsigned int	n)
{
	char				str[NUM_MAX_LEN];
	size_t				digi_slicer;
	size_t				i;

	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		i++;
	}
	else
	{
		digi_slicer = 1;
		while (n / digi_slicer >= 10)
			digi_slicer = digi_slicer * 10;
		while (digi_slicer > 0)
		{
			str[i] = '0' + (n / digi_slicer);
			n %= digi_slicer;
			i++;
			digi_slicer = digi_slicer / 10;
		}
	}
	return (write(1, str, i));
}

size_t	ft_itosx(size_t	n)
{
	char				str[NUM_MAX_LEN];
	size_t				digi_slicer;
	size_t				i;
	char				*num_s;
	size_t				j;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	num_s = "0123456789abcdef";
	digi_slicer = 1;
	while (n / digi_slicer >= 16)
		digi_slicer = digi_slicer * 16;
	while (digi_slicer > 0)
	{
		j = n / digi_slicer;
		str[i] = num_s[j];
		i++;
		n = n - j * digi_slicer;
		digi_slicer = digi_slicer / 16;
	}
	return (write(1, str, i));
}

size_t	ft_put_sx(unsigned int	num)
{
	size_t	rslt;

	rslt = 0;
	if (num >= 16)
	{
		rslt = rslt + ft_put_sx(num / 16);
	}
	rslt = rslt + write(1, &("0123456789abcdef"[num % 16]), 1);
	return (rslt);
}

size_t	ft_put_slx(unsigned int	num)
{
	size_t	res;

	res = 0;
	if (num >= 16)
	{
		res = res + ft_put_slx(num / 16);
	}
	res = res + write(1, &("0123456789ABCDEF"[num % 16]), 1);
	return (res);
}

int	ft_putnbr_fd(int	n, int	fd)
{
	int	i;

	(void)fd;
	i = 0;
	if (-9 <= n && n <= -1)
	{
		ft_putchar_fd('-', 1);
		i++;
	}
	if (n > 9 || n <= -10)
	{
		i = i + ft_putnbr_fd((n / 10), 1);
		n %= 10;
	}
	if (-9 <= n && n <= -1)
	{
		n = n * (-1);
	}
	ft_putchar_fd((n + '0'), 1);
	i++;
	return (i);
}
