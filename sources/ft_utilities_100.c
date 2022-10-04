/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:24:14 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/19 16:29:27 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_top(t_list **stack_a, int j, int l)
{
	int		i;
	int		k;
	t_list	*ptr;
	t_list	*ptr2;

	i = 0;
	ptr = (*stack_a);
	ptr2 = (*stack_a);
	k = ft_lstsize(*stack_a);
	while (k > 1)
	{
		if ((ptr2-> index >= j && ptr2-> index <= l))
			return (i);
		if (!(ptr-> index >= j && ptr-> index <= l))
		{
			i++;
			if (ptr -> next == NULL)
				break ;
			ptr = ptr-> next;
		}
		k--;
	}
	return (i);
}

int	ft_find_bottom(t_list **stack_a, int j, int l)
{
	int		m;
	t_list	*ptr1;
	int		k;

	ptr1 = (*stack_a);
	k = ft_lstsize(*stack_a);
	m = 1;
	while (ptr1->next)
		ptr1 = ptr1->next;
	while (m <= k)
	{
		if ((ptr1->index > j && ptr1->index <= l))
			break ;
		if (ptr1->prev == NULL)
			break ;
		m++;
		ptr1 = ptr1->prev;
	}
	return (m);
}

void	sort_lc_helper(int z, t_list **stack_a, t_list **stack_b)
{
	int	k;
	int	b;
	int	t;

	k = ft_lstsize(*stack_a);
	while (k > 0)
	{
		t = dist_to_top(stack_a, find_min(stack_a));
		b = k - dist_to_bottom(stack_a, find_min(stack_a));
		if (t <= b)
		{
			while (t-- > 0)
				ra(stack_a);
			k--;
			z++;
		}
		else
		{
			while (b-- > 0)
				rra(stack_a);
			k--;
			z++;
		}
		pb(stack_a, stack_b);
	}
}

void	sort_last_chunk(t_list **stack_a, t_list **stack_b)
{
	int	z;

	z = 0;
	sort_lc_helper(z, stack_a, stack_b);
	while (z-- != 0)
		pa(stack_a, stack_b);
}
