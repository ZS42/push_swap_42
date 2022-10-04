/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:31:35 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/19 17:11:16 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// fix push
//brackets around *stack if pointing to something. Otherwise no need
void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*temp;

	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dst;
	*stack_dst = temp;
}

//pa (push a): Take the first element at the top of b and
// put it at the top of a.
//Do nothing if b is empty.
void	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) == 0)
		return ;
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

//pb (push b): Take the first element at the top of a
// and put it at the top of b.
//Do nothing if a is empty
void	pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 0)
		return ;
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
