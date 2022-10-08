/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:22:40 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/06/17 04:46:45 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char	*str, ...)
{
	int		i;
	va_list	agp;
	int		len;

	va_start(agp, str);
	i = 0;
	len = 0;
	while (i < (int)(ft_strlen(str)))
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_convert(agp, str[i], &len) == 0)
				return (1);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(agp);
	return (len);
}

// int	main(void)
// {
// 	char c = 'a';
// 	char	*str = "hello";
// 	int	num = 5;

// 	printf("%c\n", c);fflush(stdout);
// 	ft_printf("%c\n", c);
// 	printf("%s\n", str);
// 	ft_printf("%s\n", str);
// 	printf("%d\n", num);
// 	ft_printf("%d\n", num);
// 	printf("%x\n", 0xabc);
// 	ft_printf("%x\n", 0xabc);
// 	printf("%p\n", str);
// 	ft_printf("%p\n", str);
// 	printf("%d\n", printf("hello%s ", "world"));
// 	ft_printf("%d\n", ft_printf("hello%s ", "world"));
// 	printf("%d\n", printf("hello%i ", 12345));
// 	ft_printf("%d\n", ft_printf("hello%i ", 12345));
// 	printf("longmax %lx\n", LONG_MAX);
// 	ft_printf("longmax %x\n", LONG_MAX);
// 	printf("longmin %lx\n", LONG_MIN);
// 	ft_printf("longmin %x\n", LONG_MIN);
// 	printf("uimax %x\n", UINT_MAX);
// 	ft_printf("uimax %x\n", UINT_MAX);
// 	printf("ulongmax %lx\n", ULONG_MAX);
// 	ft_printf("ulongmax %x\n", ULONG_MAX);
// 	printf("longmax %ld\n", LONG_MAX);
// 	ft_printf("longmax %d\n", LONG_MAX);
// 	printf("longmin %ld\n", LONG_MIN);
// 	ft_printf("longmin %d\n", LONG_MIN);
// 	printf("uimaxd %d\n", UINT_MAX);
// 	ft_printf("uimaxd %d\n", UINT_MAX);
// 	printf("uimaxu %u\n", UINT_MAX);
// 	ft_printf("uimaxu %u\n", UINT_MAX);
// 	printf("ulongmax %lu\n", ULONG_MAX);
// 	ft_printf("ulongmax %u\n", ULONG_MAX);
// 	printf("%lld\n", 9223372036854775807LL);
// 	ft_printf("%d\n", 9223372036854775807LL);
// 	return (0);
// }