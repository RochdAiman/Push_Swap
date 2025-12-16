/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:05:42 by arochd            #+#    #+#             */
/*   Updated: 2025/12/12 23:05:44 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three_items(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->head->value;
	mid = a->head->next->value;
	bottom = a->head->next->next->value;
	if (top < mid && mid < bottom)
		return ;
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && mid < bottom && top < bottom)
		sa(a);
	else if (top < mid && mid > bottom && top > bottom)
		rra(a);
	else if (top > mid && mid < bottom && top > bottom)
		ra(a);
	else if (top > mid && mid > bottom)
	{
		sa(a);
		rra(a);
	}
}

void	sort_four_items(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three_items(a);
	pa(a, b);
}

void	sort_five_items(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three_items(a);
	pa(a, b);
	pa(a, b);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->head->value > a->head->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three_items(a);
	else if (a->size == 4)
		sort_four_items(a, b);
	else if (a->size == 5)
		sort_five_items(a, b);
}
