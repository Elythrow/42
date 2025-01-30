/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:43:58 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/31 00:18:51 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void push_back_sorted(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int max = find_max(b);
		int pos = find_position(b, max);

		if (pos <= b->size / 2)
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
}

void push_chunks(t_stack *a, t_stack *b, int chunk_start, int chunk_end)
{
	int rotates = 0;
	//int found = 0;

	while (rotates < a->size)
	{
		if (a->top->value >= chunk_start && a->top->value <= chunk_end)
		{
			pb(a, b);
			//found = 1;
		}
		else
		{
			ra(a);
			rotates++;
		}
	}
}*/

void	push_chunks(t_stack *a, t_stack *b, int min, int pivot)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	while (pushed + rotated < a->size)
	{
		if (a->top->value <= pivot)
		{
			pb(a, b);
			pushed++;
		}
		else
		{
			ra(a);
			rotated++;
		}
	}
	while (rotated--)
		rra(a);
}

void	optimize_rotation(t_stack *s, int target, void (*rot)(t_stack *))
{
	int	pos;
	int	size;

	pos = find_position(s, target);
	size = s->size;
	while (pos > 0 && pos <= size / 2 && s->top->value != target)
	{
		rot(s);
		pos--;
	}
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max;

	while (b->size > 0)
	{
		max = find_max(b);
		if (find_position(b, max) <= b->size / 2)
			optimize_rotation(b, max, &rb);
		else
			optimize_rotation(b, max, &rrb);
		pa(a, b);
	}
}
