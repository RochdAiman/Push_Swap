/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:28:06 by arochd            #+#    #+#             */
/*   Updated: 2025/12/10 12:28:07 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_free(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
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

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

t_node	*stack_peek(t_stack *stack)
{
	return (stack->head);
}
