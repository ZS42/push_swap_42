/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:02:48 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/04 10:26:45 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// problem is first number is lost in lstmap so all sorting is wrong
// #include "../include/push_swap.h"
// #include <string.h>
#include "../include/push_swap.h"

// ft_free(nbr_array, k) is wrong bc the seperate strings are freed
// when lstclear str_stack and only need to free the array of pointers.
// Also dont free anything if a linked list that is being used is still
// pointing to it. So dont free nbr_array till after you free str_stack which
// is pointing to it.Similarly dont free str_stack until you are done with
// stack_a which is pointing to it.
// no need to free pointer not allocated for
// wont work without malloc of str_stack but gives extra null with it
void	create_stack(char **nbr_array, int k)
{
	int		i;
	t_list	*str_stack;
	t_list	*stack_a;

	i = 1;
	str_stack = ft_lstnew(nbr_array[0]);
	while (i < k)
	{
		if (nbr_array[i])
			ft_lstadd_back(&str_stack, ft_lstnew(nbr_array[i]));
		i++;
	}
	stack_a = ft_lstmap(str_stack, ft_atoi_ps, del);
	ft_is_duplicate(&stack_a, &str_stack, nbr_array);
	ft_int_error(&stack_a, &str_stack, nbr_array);
	stack_a = ft_index(&stack_a);
	ft_lstclear(&str_stack, del);
	free(nbr_array);
	handle_sort(stack_a);
}

void	ft_main_helper(int argc, char **argv)
{
	char	**nbr_array;
	char	*str;
	int		i;
	int		k;

	i = 1;
	nbr_array = NULL;
	str = ft_calloc(2, sizeof (char));
	str = ft_strcpy(str, " ");
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	ft_check_empty(str);
	k = ft_count_of_number(str);
	nbr_array = ft_split(str, ' ');
	ft_free_s (str);
	ft_isdigit_ps(nbr_array, k);
	create_stack(nbr_array, k);
}

//figure out how to free join
int	main(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0' || (argv[1][1] == '\0' &&
			(ft_check_space(argv[1]) == 1)))
			exit(0);
	}
	if (argc > 1)
	{
		ft_main_helper(argc, argv);
	}
}
