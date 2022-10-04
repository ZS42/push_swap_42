/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:38:59 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/13 16:12:47 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_sort(t_list *stack_a)
{
	t_list	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize(stack_a);
	if (ft_is_sorted(stack_a) == 1 || size < 2)
	{
		ft_lstclear(&stack_a, del);
		exit (0);
	}
	else if (size > 100 && size <= 500)
		sort_five_hundred(&stack_a, &stack_b);
	else if (size > 5 && size <= 100)
		sort_upto100(&stack_a, &stack_b);
	else if (size == 4 || size == 5)
		sort_five(&stack_a, &stack_b);
	else if (size == 3)
		sort_three(&stack_a, &stack_b);
	else if (size == 2)
		sa(&stack_a);
	if (stack_a)
		ft_lstclear(&stack_a, del);
	if (stack_b)
		ft_lstclear(&stack_b, del);
}

// being used == 0 if only 3 are being sorted and being_used ==1
// if another sorting function is using it.
void	sort_three(t_list **stack_a, t_list **stack_b)
{
	t_list	*top;
	t_list	*mid;
	t_list	*bottom;
	int		k;

	if (!stack_b)
		stack_b = NULL;
	k = ft_lstsize(*stack_b);
	if (ft_is_sorted(*stack_a) == 1 && k == 0)
	{
		ft_lstclear(stack_a, del);
		exit (0);
	}
	else if (ft_is_sorted(*stack_a) == 1 && k > 0)
		return ;
	top = *stack_a;
	mid = top -> next;
	bottom = mid -> next;
	ft_sort_three(stack_a, top, mid, bottom);
	if (k == 0)
		ft_lstclear(stack_a, del);
}

void	ft_sort_three(t_list **stack_a, t_list *top, t_list *mid,
			t_list *bottom)
{
	if (top -> index > mid -> index && mid -> index < bottom ->index)
	{
		if (top ->index < bottom -> index)
			sa(stack_a);
		else if (top -> index > bottom -> index)
			ra(stack_a);
	}
	else if (top -> index > mid -> index && mid -> index > bottom ->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top -> index < mid -> index && mid -> index > bottom ->index)
	{
		if (top -> index > bottom -> index)
			rra(stack_a);
		else if (top -> index < bottom -> index)
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
}
