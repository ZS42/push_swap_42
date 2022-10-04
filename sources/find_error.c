/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:14:10 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/04 10:56:59 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
// #include "../include/push_swap.h"
// use 2 in write to write to standard error instead of standard output
void	ft_isdigit_ps_helper(char **nbr_array, int k, int i)
{
	int	j;

	j = 0;
	while (nbr_array[i][j])
	{
		if ((nbr_array[i][j] == '-') || (nbr_array[i][j] == '+'))
		{
			if (!(nbr_array[i][j + 1] >= '1' && nbr_array[i][j + 1] <= '9'))
				ft_nbr_array_error(nbr_array, k);
			j++;
		}
		if ((nbr_array[i][j + 1] == '-') ||
			(nbr_array[i][j + 1] == '+'))
		{
			if (nbr_array[i][j] >= '0' && nbr_array[i][j] <= '9')
				ft_nbr_array_error(nbr_array, k);
			j++;
		}
		else if (!(nbr_array[i][j] >= '0' && nbr_array[i][j] <= '9'))
			ft_nbr_array_error(nbr_array, k);
		else if (nbr_array[i][j] >= '0' && nbr_array[i][j] <= '9')
			j++;
	}
}

int	ft_isdigit_ps(char **nbr_array, int k)
{
	int	i;

	i = -1;
	while (nbr_array[++i] != NULL)
	{
		ft_isdigit_ps_helper(nbr_array, k, i);
	}
	return (0);
}

void	ft_is_duplicate(t_list **stack_a, t_list **str_stack, char **nbr_array)
{
	t_list	*ptr;
	t_list	*ptr1;

	ptr = (*stack_a);
	ptr1 = (*stack_a)->next;
	while (ptr)
	{
		ptr1 = ptr->next;
		while (ptr1)
		{
			if (*(int *)ptr ->content == *(int *)ptr1 ->content)
			{
				write(2, "Error\n", 6);
				ft_lstclear(stack_a, del);
				ft_lstclear(str_stack, del);
				free(nbr_array);
				exit(0);
			}
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
}

// giving error for all numbers??
void	ft_int_error(t_list **stack_a, t_list **str_stack, char **nbr_array)
{
	t_list	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		if ((*((long long *)(ptr->content)) > 2147483647)
			|| ((*((long long *)(ptr->content)) < -2147483648)))
		{
			write(2, "Error\n", 6);
			ft_lstclear(str_stack, del);
			ft_lstclear(stack_a, del);
			free(nbr_array);
			exit (0);
		}
		ptr = ptr->next;
	}
}
