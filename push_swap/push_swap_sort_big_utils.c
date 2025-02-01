/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:05:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 20:43:16 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int	calculate_pivot(t_stack *s)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	int		pivot;

	arr = malloc(s->size * sizeof(int));
	if (!arr)
		exit(1);
	tmp = s->top;
	i = -1;
	while (++i < s->size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	bubble_sort(arr, s->size);
	pivot = arr[s->size / 4];
	free(arr);
	return (pivot);
}

int	calculate_pivot_high(t_stack *s)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	int		pivot;

	arr = malloc(s->size * sizeof(int));
	if (!arr)
		exit(1);
	tmp = s->top;
	i = -1;
	while (++i < s->size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	bubble_sort(arr, s->size);
	pivot = arr[s->size * 3 / 4];
	free(arr);
	return (pivot);
}

void	push_optimized(t_stack *a, t_stack *b)
{
	int	pivot;
	int	rotations;
	int	initial_size;

	initial_size = a->size;
	pivot = calculate_pivot(a);
	rotations = 0;
	while (a->size > 3 && (initial_size - a->size) < (initial_size / 2))
	{
		if (a->top->value < pivot)
		{
			pb(a, b);
			if (b->size > 1 && b->top->value < b->top->next->value)
				rb(b);
		}
		else
			(ra(a), rotations++);
	}
	balance_rotations(a, rotations);
}

void	dual_pivot_split(t_stack *a, t_stack *b)
{
	int	low_pivot;
	int	high_pivot;
	int	range;

	low_pivot = calculate_pivot(a);
	high_pivot = calculate_pivot_high(a);
	range = a->size;
	while (range-- > 0 && a->size > 100)
	{
		if (a->top->value < low_pivot)
			(pb(a, b), rb(b));
		else if (a->top->value < high_pivot)
			pb(a, b);
		else
			ra(a);
	}
}
