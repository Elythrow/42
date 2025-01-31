/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:07:06 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/31 20:27:43 by gbazin           ###   ########.fr       */
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
	int	chunk_size;
	int	median;
	int	min;
	int	max;

	chunk_size = a->size / 5;
	min = find_min(a);
	max = min + chunk_size;
	median = find_median(a);
	while (a->size > 3)
	{
		if (a->top->value <= median)
			pb(a, b);
		else
			ra(a);
		ft_printf("Stack A size: %d, Stack B size: %d\n", a->size, b->size);
	}
	sort_three(a);
	while (b->size > 0)
	{
		max = find_max(b);
		move_to_top(b, max);
		pa(a, b);
		ft_printf("Stack A size: %d, Stack B size: %d\n", a->size, b->size);
	}
}

/*void	sort_large(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	min;
	int	max;

	chunk_size = 20;
	if (a->size > 100)
		chunk_size = 50;
	min = find_min(a);
	max = find_max(a);
	while (a->size > 3)
		sort_chunk(a, b, chunk_size);
	sort_three(a);
	while (b->size > 0)
	{
		max = find_max(b);
		while (b->top->value != max)
		{
			if (find_position(b, max) <= b->size / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	chunk;
	int	i;

	min = find_min(a);
	max = find_max(a);
	chunk = (max - min) / 4;
	i = 0;
	while (i < 4)
	{
		push_chunks(a, b, min + chunk * (i + 1));
		i++;
	}
	while (a->size > 0)
		pb(a, b);
	push_back_sorted(a, b);
}
void	sort_large(t_stack *a, t_stack *b)
{
	int chunk_size;
	int	min;
	int	max;
	int	i;
	int	d;

	chunk_size = a->size / 4;
	min = find_min(a);
	max = find_max(a);
	d = max - min;
	i = 0;
	while (i < chunk_size)
	{
		push_chunks(a, b, min + d * i / 4, min + d * (i + 1) / 4);
		i++;
	}
	while (a->size > 0)
		pb(a, b);
	push_back_sorted(a, b);
}*/