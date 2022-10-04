/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 08:44:41 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/19 13:12:57 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../include/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list	*ft_index(t_list **stack)
{
	int		count;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1 != NULL)
	{
		temp2 = *stack;
		count = 1;
		while (temp2 != NULL)
		{
			if (*((int *)(temp1->content)) > *((int *)(temp2->content)))
				count++;
			temp2 = temp2 ->next;
		}
		temp1->index = count;
		temp1 = temp1 -> next;
	}
	return (*stack);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_print_list_prev(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	while (ptr != NULL)
	{
		ft_printf("%d, ", ptr->index);
		ptr = ptr->prev;
	}
	ft_printf("\n");
	return ;
}
