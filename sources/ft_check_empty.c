/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:10:04 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/04 10:53:14 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f')
		return (1);
	else
		return (0);
}

void	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	while (ft_check_space(str + i) == 1)
		i++;
	if (str[i] == '\0')
	{
		ft_free_s(str);
		exit (0);
	}
}

void	ft_nbr_array_error(char **nbr_array, int k)
{
	write(2, "Error\n", 6);
	ft_free(nbr_array, k);
	exit (0);
}
