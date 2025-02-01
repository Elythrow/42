/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:50:44 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 20:52:48 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rotations(t_stack *s, int count, void (*f)(t_stack *))
{
	while (count-- > 0)
		f(s);
}

void	rotate_to_min(t_stack *a)
{
	int	min_val;
	int	pos;
	int	rot;

	min_val = find_min(a);
	pos = find_position(a, min_val);
	rot = pos;
	if (pos > a->size / 2)
		rot = pos - a->size;
	if (rot > 0)
		exec_rotations(a, rot, ra);
	else
		exec_rotations(a, -rot, rra);
}

void	smart_rotate_a(t_stack *a)
{
	int	rotations;
	int	val;

	rotations = 0;
	val = a->top->value;
	while (a->top->next && val > a->top->next->value)
	{
		ra(a);
		rotations++;
	}
	if (rotations > a->size / 2)
		exec_rotations(a, a->size - rotations, rra);
}

void	balance_rotations(t_stack *a, int rotations)
{
	int	reverse;

	reverse = a->size - rotations;
	if (rotations <= reverse)
		exec_rotations(a, rotations, rra);
	else
		exec_rotations(a, reverse, ra);
}

void	align_stack_a(t_stack *a)
{
	int	min_pos;
	int	rot;

	min_pos = find_position(a, find_min(a));
	if (min_pos <= a->size / 2)
		rot = min_pos;
	else
		rot = min_pos - a->size;
	while (rot > 0 && rot--)
		ra(a);
	while (rot < 0 && rot++)
		rra(a);
}
