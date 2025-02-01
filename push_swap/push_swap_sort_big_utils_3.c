/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils_3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:52:09 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 20:53:41 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_b_rot(t_stack *b, int target)
{
	int	pos;
	int	rot;

	pos = find_position(b, target);
	if (pos <= b->size / 2)
		rot = pos;
	else
		rot = pos - b->size;
	return (rot);
}

int	calc_a_rot(t_stack *a, int value)
{
	int		best_pos;
	t_node	*tmp;
	int		i;

	tmp = a->top;
	best_pos = 0;
	i = 0;
	while (++i <= a->size)
	{
		if (value > tmp->value && (tmp->next == NULL
				|| value < tmp->next->value))
			best_pos = i % a->size;
		tmp = tmp->next;
	}
	if (best_pos <= a->size / 2)
		return (best_pos);
	return (best_pos - a->size);
}

void	execute_rotations(t_stack *a, t_stack *b, int a_rot, int b_rot)
{
	while (a_rot > 0 && b_rot > 0 && a_rot-- && b_rot--)
		rr(a, b);
	while (a_rot < 0 && b_rot < 0 && a_rot++ && b_rot++)
		rrr(a, b);
	while (a_rot > 0 && a_rot--)
		ra(a);
	while (a_rot < 0 && a_rot++)
		rra(a);
	while (b_rot > 0 && b_rot--)
		rb(b);
	while (b_rot < 0 && b_rot++)
		rrb(b);
}

void	optimize_b_rotation(t_stack *a, t_stack *b)
{
	int	target;
	int	a_rot;
	int	b_rot;

	while (b->size > 0)
	{
		target = find_max(b);
		b_rot = calc_b_rot(b, target);
		a_rot = calc_a_rot(a, target);
		execute_rotations(a, b, a_rot, b_rot);
		pa(a, b);
		if (a->top->value != find_max(a))
			smart_rotate_a(a);
		else
			rra(a);
	}
}
