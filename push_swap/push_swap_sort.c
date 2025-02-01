/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:07:06 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 20:53:54 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = stack_a->top->value;
	mid = stack_a->top->next->value;
	bottom = stack_a->top->next->next->value;
	if (top > mid && mid < bottom && top < bottom)
		sa(stack_a);
	else if (top > mid && mid > bottom)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top > mid && mid < bottom && top > bottom)
		ra(stack_a);
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(stack_a);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	pos;

	while (stack_a->size > 3)
	{
		min = find_min(stack_a);
		pos = find_position(stack_a, min);
		while (stack_a->top->value != min)
		{
			if (pos <= stack_a->size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	sort_large(t_stack *a, t_stack *b)
{
	while (a->size > 100)
		dual_pivot_split(a, b);
	while (a->size > 3)
		push_optimized(a, b);
	sort_three(a);
	optimize_b_rotation(a, b);
	align_stack_a(a);
}
