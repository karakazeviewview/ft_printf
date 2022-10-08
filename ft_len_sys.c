/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_sys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:44:36 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/06/15 21:52:49 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const	char	*str)
{
	size_t	len;

	len = 0;
	while (*(str + len) != '\0')
		len++;
	return (len);
}

size_t	ft_numlen16(size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
