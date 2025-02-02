/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:05:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/02 01:01:32 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	min = find_min(a);
	while (a->top->value != min)
	{
		pos = find_position(a, min);
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_b_to_a(t_stack *a, t_stack *b)
{
	int	max_b;
	int	pos;

	while (b->size > 0)
	{
		max_b = find_max(b);
		while (b->top->value != max_b)
		{
			pos = find_position(b, max_b);
			if (pos <= b->size / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	final_sort(t_stack *a)
{
	int	min;
	int	pos;

	min = find_min(a);
	while (a->top->value != min)
	{
		pos = find_position(a, min);
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}
