/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:05:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/02 14:31:40 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	push_max_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	max_pos;

	max = find_max(b);
	max_pos = find_position(b, max);
	if (max_pos <= b->size / 2)
	{
		while (b->top->value != max)
			rb(b);
	}
	else
	{
		while (b->top->value != max)
			rrb(b);
	}
	pa(a, b);
}

int	has_numbers_in_range(t_stack *stack, int min_val, int max_val)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value >= min_val && current->value < max_val)
			return (1);
		current = current->next;
	}
	return (0);
}
