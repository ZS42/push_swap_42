/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:11:17 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/04 10:46:14 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//for using exit function
# include <stdlib.h> // to use exit
# include <unistd.h>
//#include <limits.h> to use max and min
// # include "libft.h"
# include "../libft/include/libft.h"

// use with make
void		ft_main_helper(int argc, char **argv);
void		ft_check_empty(char *str);
int			ft_check_space(char *str);
char		*ft_strcpy(char *dest, char *src);
void		ft_int_error(t_list **stack_a, t_list **str_stack,
				char **nbr_array);
void		ft_nbr_array_error(char **nbr_array, int k);
void		ft_free(char **nbr_array, int i);
void		del(void *s);
void		ft_isdigit_ps_helper(char **nbr_array, int k, int i);
int			ft_isdigit_ps(char **nbr_array, int k);
void		ft_is_duplicate(t_list **stack_a, t_list **str_stack,
				char **nbr_array);
long long	ft_atoi_ps(t_list *str);
int			ft_is_space(t_list *str);
int			ft_count_of_number(char *str);
void		ft_create_stack(char **nbr_array, int k);
t_list		*ft_index(t_list **stack);

/* ******************************operations********************************* */

void		push(t_list **stack_dst, t_list **stack_src);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ft_swap(int *a, int *b);
void		swap(t_list **stack);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		rotate(t_list **stack);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rev_rotate(t_list **stack);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);

/* *******************************sort************************************** */

int			ft_is_sorted(t_list *stack);
void		handle_sort(t_list *stack_a);
void		sort_five_hundred(t_list **stack_a, t_list **stack_b);
void		sort_upto100(t_list **stack_a, t_list **stack_b);
void		ft_sort_large(t_list **stack, t_list **stack_b, int j, int l);
void		send_to_b(t_list **stack_a, t_list **stack_b, int i, int k);
void		send_to_stack_b(t_list **stack_a, t_list **stack_b);
void		ft_push_min(t_list **stack_a, t_list **stack_b);
void		sort_five(t_list **stack_a, t_list **stack_b);
void		ft_sort_three(t_list **stack_a, t_list *top, t_list *mid,
				t_list *bottom);
void		sort_three(t_list **stack_a, t_list **stack_b);
int			find_max(t_list **stack);
int			find_min(t_list **stack);
int			dist_to_top(t_list **stack, int index);
int			dist_to_bottom(t_list **stack, int index);
int			ft_find_top(t_list **stack_a, int j, int l);
int			ft_find_bottom(t_list **stack_a, int j, int l);
void		send_to_a(t_list **stack_a, t_list **stack_b);
void		sort_last_chunk(t_list **stack_a, t_list **stack_b);
void		ft_print_list_prev(t_list	*lst);
void		sort_lc_helper(int z, t_list **stack_a, t_list **stack_b);

#endif
