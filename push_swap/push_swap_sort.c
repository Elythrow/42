/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:07:06 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/31 00:21:21 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	if (stack_a->size != 3)
		return ;
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}*/

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
	int	size;
	int	min;
	int	max;
	int	chunk;
	int	i;

	size = a->size;
	min = find_min(a);
	max = find_max(a);
	chunk = (max - min) / 4;
	i = 0;
	while (i < 4)
	{
		push_chunks(a, b, min, min + chunk * (i + 1));
		i++;
	}
	while (a->size > 0)
		pb(a, b);
	push_back_sorted(a, b);
}

/*void	sort_large(t_stack *a, t_stack *b)
{
	int chunk_size;
	int	min;
	int	max;
	int	i;
	int	d;

	//if (is_sorted(a))
	//	return; // Already sorted
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
