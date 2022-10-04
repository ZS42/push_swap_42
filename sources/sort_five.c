/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:30:17 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/19 12:10:47 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_min(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	k;

	i = 0;
	k = ft_lstsize(*stack_a);
	while (i < k && dist_to_top(stack_a, find_min(stack_a)) != 0)
	{
		if (dist_to_top(stack_a, find_min(stack_a)) > k / 2)
			rra(stack_a);
		else
			ra(stack_a);
		i++;
	}
	pb(stack_a, stack_b);
}

//second pa wont do anythig if lstsize is 4
void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_is_sorted(*stack_a) == 1)
		exit (0);
	if (ft_lstsize(*stack_a) == 5)
		ft_push_min(stack_a, stack_b);
	ft_push_min(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	if (ft_lstsize(*stack_b) == 2)
		pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ft_lstclear(stack_a, del);
}
