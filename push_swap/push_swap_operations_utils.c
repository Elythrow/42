/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:02:17 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 23:44:20 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
}

void	push_to_stack(t_stack *src, t_stack *dst)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	src->size--;
	temp->next = dst->top;
	dst->top = temp;
	dst->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
