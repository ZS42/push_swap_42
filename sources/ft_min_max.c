/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:54:59 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/19 13:09:52 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **stack)
{
	t_list	*ptr;
	int		max;

	ptr = *stack;
	max = ptr -> index;
	while (ptr != NULL)
	{
		if (max < ptr -> index)
			max = ptr -> index;
		ptr = ptr->next;
	}
	return (max);
}

int	find_min(t_list **stack)
{
	t_list	*ptr;
	int		min;

	ptr = *stack;
	min = ptr -> index;
	while (ptr)
	{
		if (min > ptr -> index)
			min = ptr -> index;
		ptr = ptr -> next;
	}
	return (min);
}

int	dist_to_top(t_list **stack, int index)
{
	int		distance;
	t_list	*ptr;

	distance = 0;
	ptr = *stack;
	while (ptr -> index != index)
	{
		ptr = ptr -> next;
		distance++;
	}
	return (distance);
}

int	dist_to_bottom(t_list **stack, int number)
{
	int		distance;
	t_list	*ptr;

	ptr = *stack;
	distance = 0;
	while (ptr->index != number)
	{
		ptr = ptr->next;
		distance++;
	}
	return (distance);
}
