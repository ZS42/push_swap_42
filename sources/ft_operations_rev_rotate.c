/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rev_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:21:25 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/18 21:10:52 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*new_head;
	t_list	*old_head;

	old_head = *stack;
	new_head = *stack;
	new_head = (ft_lstlast(*stack));
	while (old_head -> next -> next)
		old_head = old_head ->next;
	old_head -> next = NULL;
	new_head -> next = *stack;
	(*stack)->prev = new_head;
	*stack = new_head;
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	write (1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	write (1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write (1, "rr\n", 3);
}
