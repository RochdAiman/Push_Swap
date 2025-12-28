/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:16:07 by arochd            #+#    #+#             */
/*   Updated: 2025/12/13 16:16:09 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	calc_chunk_size(int size)
{
	if (size <= 100)
		return (18);
	if (size <= 500)
		return (size / 12);
	return (size / 13);
}

int	find_max_index_position(t_stack *stack)
{
	t_node	*node;
	int		max_index;
	int		max_index_pos;
	int		pos;

	node = stack->head;
	max_index = node->index;
	max_index_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->index > max_index)
		{
			max_index = node->index;
			max_index_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_index_pos);
}

int	is_in_chunk(int index, int min_val, int max_val)
{
	return (index >= min_val && index <= max_val);
}
