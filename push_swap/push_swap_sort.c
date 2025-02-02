/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:07:06 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/02 01:01:34 by gbazin           ###   ########.fr       */
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
	int	chunks;
	int	min;
	int	max;
	int	range;
	int	chunk_max;

	chunks = 5;
	min = find_min(a);
	max = find_max(a);
	range = (max - min) / chunks;
	chunk_max = min + range;
	while (a->size > 3)
	{
		if (a->top->value <= chunk_max)
		{
			pb(a, b);
			if (b->size > 1 && b->top->value > b->top->next->value)
				rb(b);
		}
		else if (find_min(a) > chunk_max)
			chunk_max += range;
		else
			ra(a);
	}
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 2)
		sort_two(a);
	sort_b_to_a(a, b);
	final_sort(a);
	print_stack(a, "a");
}

void	print_stack(t_stack *s, char *name)
{
	t_node	*tmp;

	tmp = s->top;
	ft_printf("\n%s: ", name);
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
