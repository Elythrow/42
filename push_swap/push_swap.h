/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:07:14 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 20:54:34 by gbazin           ###   ########.fr       */
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
void	bubble_sort(int *arr, int size);
int		calculate_pivot(t_stack *s);
int		calculate_pivot_high(t_stack *s);
void	push_optimized(t_stack *a, t_stack *b);
void	dual_pivot_split(t_stack *a, t_stack *b);
void	exec_rotations(t_stack *s, int count, void (*f)(t_stack *));
void	rotate_to_min(t_stack *a);
void	smart_rotate_a(t_stack *a);
void	balance_rotations(t_stack *a, int rotations);
void	smart_rotate_a(t_stack *a);
void	rotate_to_min(t_stack *a);
void	align_stack_a(t_stack *a);
void	optimize_b_rotation(t_stack *a, t_stack *b);
void	execute_rotations(t_stack *a, t_stack *b, int a_rot, int b_rot);
int		calc_a_rot(t_stack *a, int value);
int		calc_b_rot(t_stack *b, int target);

#endif