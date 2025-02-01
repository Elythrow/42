/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:05:49 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 17:57:09 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->value == value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

void	smart_rotate_a(t_stack *a)
{
	int	val;
	int	rotations;

	val = a->top->value;
	rotations = 1;
	while (a->top->next && !(val > a->top->next->value))
	{
		ra(a);
		rotations++;
	}
	if (rotations > a->size / 2)
		while (a->size - rotations++ > 0)
			rra(a);
}

void	rotate_to_min(t_stack *a)
{
	int	min_pos;
	int	mid;

	min_pos = find_position(a, find_min(a));
	mid = a->size / 2;
	if (min_pos <= mid)
		while (min_pos-- > 0)
			ra(a);
	else
		while (a->size - min_pos++ > 0)
			rra(a);
}