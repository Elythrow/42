/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils_3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:52:09 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 23:12:26 by gbazin           ###   ########.fr       */
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
	int		min_val;
	int		max_val;
	t_node	*tmp;
	int		i;

	min_val = find_min(a);
	max_val = find_max(a);
	tmp = a->top;
	i = 0;
	if (value < min_val)
		return (find_position(a, min_val));
	if (value > max_val)
		return (find_position(a, max_val) + 1);
	while (tmp->next != NULL)
	{
		if (value > tmp->value && value < tmp->next->value)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i + 1 <= a->size / 2)
		return (i + 1);
	else
		return ((i + 1) - a->size);
}

void	execute_rotations(t_stack *a, t_stack *b, int a_rot, int b_rot)
{
	while (a_rot > 0 && b_rot > 0)
	{
		rr(a, b);
		a_rot--;
		b_rot--;
	}
	while (a_rot < 0 && b_rot < 0)
	{
		rrr(a, b);
		a_rot++;
		b_rot++;
	}
	while (a_rot-- > 0)
		ra(a);
	while (a_rot++ < 0)
		rra(a);
	while (b_rot-- > 0)
		rb(b);
	while (b_rot++ < 0)
		rrb(b);
}

void    optimize_b_rotation(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        // Find position of maximum value in B
        int max = find_max(b);
        int pos = find_position(b, max);

        // Rotate B to get max value to top (using shortest path)
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

        // Push to A and rotate A if needed
        pa(a, b);
    }

    // Find the minimum value in A and rotate to put it on top
    int min = find_min(a);
    int min_pos = find_position(a, min);

    // Rotate A to get min value to top (using shortest path)
    if (min_pos <= a->size / 2)
    {
        while (a->top->value != min)
            ra(a);
    }
    else
    {
        while (a->top->value != min)
            rra(a);
    }
}
