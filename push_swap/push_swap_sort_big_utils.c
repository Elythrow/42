/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:43:58 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/31 20:27:35 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void push_back_sorted(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int max = find_max(b);
		int pos = find_position(b, max);

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
		pa(a, b);
	}
}

void push_chunks(t_stack *a, t_stack *b, int chunk_start, int chunk_end)
{
	int rotates = 0;
	//int found = 0;

	while (rotates < a->size)
	{
		if (a->top->value >= chunk_start && a->top->value <= chunk_end)
		{
			pb(a, b);
			//found = 1;
		}
		else
		{
			ra(a);
			rotates++;
		}
	}
}*/

/*void	sort_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	pushed;
	int	min;
	int	max;

	i = 0;
	pushed = 0;
	min = find_min(a);
	max = min + chunk_size;
	while (i < a->size && pushed < chunk_size)
	{
		if (a->top->value >= min && a->top->value < max)
		{
			pb(a, b);
			pushed++;
		}
		else
		{
			ra(a);
		}
		i++;
	}
}

void	optimize_rotation(t_stack *s, int target, void (*rot)(t_stack *))
{
	int	pos;
	int	size;

	pos = find_position(s, target);
	size = s->size;
	while (pos > 0 && pos <= size / 2 && s->top->value != target)
	{
		rot(s);
		pos--;
	}
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max;

	while (b->size > 0)
	{
		max = find_max(b);
		if (find_position(b, max) <= b->size / 2)
			optimize_rotation(b, max, &rb);
		else
			optimize_rotation(b, max, &rrb);
		pa(a, b);
	}
}*/

void	move_to_top(t_stack *stack, int target)
{
	int	pos;

	while (stack->top->value != target)
	{
		pos = find_position(stack, target);
		if (pos <= stack->size / 2)
			rb(stack);
		else
			rrb(stack);
		ft_printf("Moved to target %d, Stack size: %d\n", target, stack->size);
	}
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	find_median(t_stack *stack)
{
	int		*sorted_array;
	int		size;
	int		median;
	t_node	*current;
	int		i;

	size = stack->size;
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
		return (0);
	current = stack->top;
	i = 0;
	while (i < size)
	{
		sorted_array[i] = current->value;
		current = current->next;
		i++;
	}
	sort_array(sorted_array, size);
	median = sorted_array[size / 2];
	free(sorted_array);
	return (median);
}
