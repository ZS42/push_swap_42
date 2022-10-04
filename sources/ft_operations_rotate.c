/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:26:28 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/19 10:04:05 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*new_head;
	t_list	*old_head;
	t_list	*ptr;

	old_head = *stack;
	ptr = old_head;
	new_head = old_head-> next;
	while (old_head->next)
			old_head = old_head->next;
	old_head -> next = ptr;
	ptr->next = NULL;
	ptr ->prev = old_head;
	new_head -> prev = NULL;
	(*stack) = new_head;
}

//ra (rotate a): Shift up all elements of stack a by 1
//The first element becomes the last one.
void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3);
}

//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write (1, "rb\n", 3);
}

//rr : ra and rb at the same time.
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
