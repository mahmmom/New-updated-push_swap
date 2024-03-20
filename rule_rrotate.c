/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:44:03 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/11 20:48:16 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	if (!stack)
		return ;
	head = (*stack);
	while (head->next != NULL)
	{
		temp = head;
		head = head->next;
	}
	head->next = (*stack);
	temp->next = NULL;
	(*stack) = head;
}

void	rra(t_stack **a, bool print)
{
	r_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool print)
{
	r_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (!print)
		write(1, "rrr\n", 4);
}
