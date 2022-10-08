/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:47:31 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/06/15 21:59:42 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define NUM_MAX_LEN 16

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char	*str, ...);
size_t	ft_strlen(const	char	*str);
size_t	ft_numlen16(size_t		n);
void	ft_putchar_fd(char		c, int	fd);
void	ft_putstr_fd(char		*s, int	fd);
size_t	ft_string(char			*str);
size_t	ft_itosu(unsigned int	n);
size_t	ft_itosx(size_t			n);
size_t	ft_put_sx(unsigned int	num);
size_t	ft_put_slx(unsigned int	num);
int		ft_putnbr_fd(int		n, int	fd);
size_t	ft_convert_2(va_list	agp, char c, int *len);
size_t	ft_convert(va_list		agp, char c, int *len);

#endif