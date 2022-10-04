/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_upto100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:45:42 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/03 15:55:45 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// dont let linkedist go to NULL or you cant go back up the list
void	ft_sort_large(t_list **stack_a, t_list **stack_b, int j, int l)
{
	int	i;
	int	m;

	while ((ft_lstsize(*stack_b)) < l)
	{
		i = ft_find_top(stack_a, j, l);
		m = ft_find_bottom(stack_a, j, l);
		send_to_b(stack_a, stack_b, i, m);
	}
}

void	send_to_b(t_list **stack_a, t_list **stack_b, int i, int m)
{
	if (m < i)
	{
		while (m != 0)
		{
			rra(stack_a);
			m--;
		}
	}
	else
	{
		while (i != 0)
		{
			ra(stack_a);
			i--;
		}
	}
	pb(stack_a, stack_b);
}

void	send_to_a(t_list **stack_a, t_list **stack_b)
{
	int	t;
	int	m;

	while (ft_lstsize(*stack_b) != 0)
	{
		t = dist_to_top(stack_b, find_max(stack_b));
		m = ft_lstsize(*stack_b) - dist_to_bottom(stack_b, find_max(stack_b));
		if (m < t)
		{
			while (m != 0)
			{
				rrb(stack_b);
				m--;
			}
		}
		else
		{
			while (t != 0)
			{
				rb(stack_b);
					t--;
			}
		}
		pa(stack_a, stack_b);
	}
}

void	sort_upto100(t_list **stack_a, t_list **stack_b)
{
	int	k;

	k = ft_lstsize(*stack_a);
	ft_sort_large(stack_a, stack_b, k * 0, k * 0.25);
	ft_sort_large(stack_a, stack_b, k * 0.25, k * 0.5);
	ft_sort_large(stack_a, stack_b, k * 0.5, k * 0.75);
	if ((ft_is_sorted(*stack_a)) == 0)
		sort_last_chunk(stack_a, stack_b);
	send_to_a(stack_a, stack_b);
	ft_lstclear(stack_a, del);
	if (stack_b)
		ft_lstclear(stack_a, del);
}
