/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:43:59 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/11 20:48:20 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = NULL;
	ft_stack_add_back(stack, temp);
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (!print)
		write(1, "rr\n", 3);
}
