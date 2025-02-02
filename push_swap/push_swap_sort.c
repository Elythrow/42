/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:07:06 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/02 11:48:00 by gbazin           ###   ########.fr       */
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
	int	chunk;
	int	max_chunks;

	max_chunks = 5;
	if (a->size > 100)
		max_chunks = 9;
	chunk_size = ((find_max(a) - find_min(a)) + max_chunks - 1) / max_chunks;
	chunk = find_min(a);
	while (a->size > 0)
	{
		if (a->top->value >= chunk && a->top->value < (chunk + chunk_size))
		{
			pb(a, b);
			if (b->size > 1 && b->top->value < (chunk + chunk_size / 2))
				rb(b);
		}
		else if (has_numbers_in_range(a, chunk, chunk + chunk_size))
			ra(a);
		else
			chunk += chunk_size;
	}
	while (b->size > 0)
		push_max_to_a(a, b);
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
