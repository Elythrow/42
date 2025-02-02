/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:25:01 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/01 22:32:55 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return (0);
	new_node = create_node(value);
	if (!new_node)
		return (0);
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (1);
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack || !stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (value);
}
