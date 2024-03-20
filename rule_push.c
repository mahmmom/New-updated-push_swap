/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:43:54 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/11 20:57:10 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push1(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	(*src) = (*src)->next;
	temp->next = *dest;
	(*dest) = temp;
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push1(b, a);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push1(a, b);
	if (!print)
		write(1, "pb\n", 3);
}
