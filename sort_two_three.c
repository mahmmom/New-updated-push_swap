/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:44:16 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/11 20:57:20 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	int	num1;
	int	num2;

	num1 = (*a)->content;
	num2 = (*a)->next->content;
	if (num1 > num2)
		sa(a, false);
}

void	sort_3(t_stack **a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*a)->content;
	num2 = (*a)->next->content;
	num3 = (*a)->next->next->content;
	if (num1 < num2 && num2 < num3 && num1 < num3)
		return ;
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(a, false);
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(a, false);
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(a, false);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		sa(a, false);
		rra(a, false);
	}
}

bool	sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}

void	sort_2_3(t_stack **stack)
{
	t_stack	*temp;
	int		len;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	len = ft_stack_size(temp);
	if (len == 2)
		sort_2(stack);
	else if (len == 3)
		sort_3(stack);
}
