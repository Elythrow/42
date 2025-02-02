/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:07:14 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/02 14:39:43 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	sort_stack(t_stack *stack_a, t_stack *stack_b);
t_stack	*create_stack(void);
t_node	*create_node(int value);
void	free_stack(t_stack *stack);
int		push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	push_to_stack(t_stack *src, t_stack *dst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	sort_three(t_stack *stack_a);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);
int		has_duplicates(t_stack *stack, int num);
int		parse_and_add(t_stack *stack, char *str);
int		parse_string_input(t_stack *stack, char *str);
void	reverse_stack(t_stack *stack);
int		parse_args(t_stack *stack, int ac, char **av);
int		ft_is_number(char *str);
void	print_stack(t_stack *s, char *name);
void	sort_two(t_stack *a);
void	push_max_to_a(t_stack *a, t_stack *b);
int		has_numbers_in_range(t_stack *stack, int min_val, int max_val);
int		is_sorted(t_stack *stack);

#endif