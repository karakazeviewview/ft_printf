/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_sys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:01:55 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/06/15 21:56:41 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char	c, int	fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char	*s, int	fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (*(s + i) != '\0')
		i++;
	write(fd, s, i);
}

size_t	ft_string(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	else
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}
