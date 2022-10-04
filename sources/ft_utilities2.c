/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:50:56 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/03 17:05:18 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_ps(t_list *str)
{
	int				sign;
	int				i;
	long long int	k;

	k = 0;
	i = 0;
	sign = 1;
	while (((char *)str->content)[i] == ' ')
		i++;
	if (((char *)str->content)[i] == '-')
	{
			sign *= -1;
			i++;
	}
	if (((char *)str->content)[i] == '-' || ((char *)str->content)[i] == '+')
		i++;
	while (((char *)str->content)[i] >= '0' &&
		((char *)str->content)[i] <= '9' && ((char *)str->content)[i])
	{
		k = k * 10 + ((char *)str->content)[i] - '0';
		i++;
	}
	return (k * sign);
}

int	ft_is_sorted(t_list *stack)
{
	t_list	*temp1;
	int		flag;

	temp1 = stack;
	flag = 1;
	while (temp1 -> next != NULL)
	{
		if (temp1 -> index > temp1 -> next -> index)
			flag = 0;
		temp1 = temp1 -> next;
	}
	return (flag);
}

void	ft_free(char **nbr_array, int i)
{
	i = -1;
	if (nbr_array)
	{
		while (nbr_array[++i])
			free(nbr_array[i]);
		free(nbr_array);
	}
}

int	ft_count_of_number(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
			i++;
		if ((str[i] != 32 && str[i + 1] == 32)
			|| (str[i] != 32 && (str[i + 1] == '\0')))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}
