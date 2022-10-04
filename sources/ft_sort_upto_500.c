/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_upto_500.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:07:04 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/03 15:52:44 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_hundred(t_list **stack_a, t_list **stack_b)
{
	int	k;

	k = ft_lstsize(*stack_a);
	ft_sort_large(stack_a, stack_b, k * 0, k * 0.1);
	ft_sort_large(stack_a, stack_b, k * 0.1, k * 0.2);
	ft_sort_large(stack_a, stack_b, k * 0.2, k * 0.3);
	ft_sort_large(stack_a, stack_b, k * 0.3, k * 0.4);
	ft_sort_large(stack_a, stack_b, k * 0.4, k * 0.5);
	ft_sort_large(stack_a, stack_b, k * 0.5, k * 0.6);
	ft_sort_large(stack_a, stack_b, k * 0.6, k * 0.7);
	ft_sort_large(stack_a, stack_b, k * 0.7, k * 0.8);
	ft_sort_large(stack_a, stack_b, k * 0.8, k * 0.9);
	if ((ft_is_sorted(*stack_a)) == 0)
		sort_last_chunk(stack_a, stack_b);
	send_to_a(stack_a, stack_b);
	ft_lstclear(stack_a, del);
	if (stack_b)
		ft_lstclear(stack_a, del);
}
