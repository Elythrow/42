/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:50:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/21 12:20:07 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	parse_and_add(t_stack *stack, char *str)
{
	long	num;
	t_node	*new_node;

	if (!is_number(str))
		return (0);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (has_duplicates(stack, (int)num))
		return (0);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = (int)num;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (1);
}

int	parse_string_input(t_stack *stack, char *str)
{
	char	**split;
	int		i;
	int		success;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = 0;
	success = 1;
	while (split[i] && success)
	{
		success = parse_and_add(stack, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (success);
}

void	reverse_stack(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;
	t_node	*next;

	prev = NULL;
	current = stack->top;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	stack->top = prev;
}

int	parse_args(t_stack *stack, int ac, char **av)
{
	int	i;
	int	success;

	i = 1;
	success = 1;
	if (ac == 2)
		success = parse_string_input(stack, av[1]);
	else
	{
		while (i < ac && success)
		{
			success = parse_and_add(stack, av[i]);
			i++;
		}
	}
	if (success)
		reverse_stack(stack);
	return (success);
}
