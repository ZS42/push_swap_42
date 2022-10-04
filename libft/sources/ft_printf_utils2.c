/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:41:34 by zsyyida           #+#    #+#             */
/*   Updated: 2022/08/30 12:45:27 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char(char c, int *len)
{
	write(1, &c, 1);
	*len = *len + 1;
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (s == NULL)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

void	ft_putstr(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
		return ;
	}
	while (i < ft_strlen(s))
	{
		ft_print_char(s[i], len);
		i++;
	}
	return ;
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_print_char('-', len);
		ft_putnbr(-n, len);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_print_char(n % 10 + '0', len);
	return ;
}

void	ft_print_u(unsigned int n, int *len)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_print_char(n + '0', len);
	return ;
}
