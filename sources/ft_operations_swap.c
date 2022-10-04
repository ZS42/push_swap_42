/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:27:25 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/15 12:32:38 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*top;
	t_list	*second;
	int		k;

	k = ft_lstsize(*stack);
	if (k < 2)
		return ;
	else if (k >= 2)
	{
		top = *stack;
		second = top -> next;
		ft_swap(&top -> index, &second -> index);
		second->prev = NULL;
		top->prev = second;
	}
}

//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	sa(t_list **stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
}

//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void	sb(t_list **stack_b)
{
	swap(stack_b);
	write (1, "sb\n", 3);
}

//ss : sa and sb at the same time.
void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
}
