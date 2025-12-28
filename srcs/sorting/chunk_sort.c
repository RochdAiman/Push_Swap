/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:22:58 by arochd            #+#    #+#             */
/*   Updated: 2025/12/14 14:46:06 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bring_max_top(t_stack *b)
{
	int	max_pos;
	int	size;

	max_pos = find_max_index_position(b);
	size = b->size;
	if (max_pos == 0)
		return ;
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(b);
	}
	else
		while (max_pos++ < size)
			rrb(b);
}
int get_pos_by_index(t_stack *stack, int target_index)
{
    t_node	*node;
    int		pos;

    node = stack->head;
    pos = 0;
    while (node)
    {
        if (node->index == target_index)
            return (pos);
        node = node->next;
        pos++;
    }
    return (-1);
}

void    push_back_to_a(t_stack *a, t_stack *b)
{
    int max_i;
    int pos_max;
    int pos_next;

    while (b->size > 0)
    {
        max_i = b->size - 1;
        pos_max = get_pos_by_index(b, max_i);
        pos_next = get_pos_by_index(b, max_i - 1);
        if (b->size > 1 && pos_next == 0)
        {
            pa(a, b);
            bring_max_top(b);
            pa(a, b);
            sa(a);
        }
        else
        {
            bring_max_top(b);
            pa(a, b);
        }
    }
}

void	chunking_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk;

	index_stack_nodes(a);
	i = 0;
	chunk = calc_chunk_size(a->size);
	while (a->size > 0)
	{
		if (a->head->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->head->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}
