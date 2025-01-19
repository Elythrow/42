/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:43:58 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/19 20:57:46 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;

	while (b->size > 0)
	{
		max = find_max(b);
		pos = find_position(b, max);
		while (b->top->value != max)
		{
			if (pos <= b->size / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	push_chunks(t_stack *a, t_stack *b, int chunk_start, int chunk_end)
{
	int	found;
	int	rotates;

	rotates = 0;
	while (1)
	{
		found = 0;
		if (a->top->value >= chunk_start && a->top->value <= chunk_end)
		{
			pb(a, b);
			found = 1;
		}
		else
		{
			ra(a);
			rotates++;
		}
		if (!found && rotates >= a->size)
			break ;
	}
}
