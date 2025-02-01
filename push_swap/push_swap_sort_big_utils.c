/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:05:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 17:55:03 by gbazin           ###   ########.fr       */
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

int	get_pivot(t_stack *s)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	int		pivot;

	arr = (int *)malloc(s->size * sizeof(int));
	if (!arr)
		return (-1);
	tmp = s->top;
	i = -1;
	while (i + 1 < s->size)
	{
		i++;
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	bubble_sort(arr, s->size);
	pivot = arr[s->size / 2];
	free(arr);
	return (pivot);
}

void	rotate_max_to_top(t_stack *b)
{
	int	max_val;
	int	pos;
	int	mid;

	max_val = find_max(b);
	pos = find_position(b, max_val);
	mid = b->size / 2;
	if (pos <= mid)
		while (pos-- > 0)
			rb(b);
	else
		while (b->size - pos++ > 0)
			rrb(b);
}

void	push_chunk(t_stack *a, t_stack *b, int pivot)
{
	int	remaining;

	remaining = a->size;
	while (remaining-- > 0)
	{
		if (a->top->value < pivot)
			pb(a, b);
		else
			ra(a);
		if (find_min(a) >= pivot)
			break ;
	}
}
