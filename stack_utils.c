/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:44:20 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/11 20:57:49 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	long	highest;

	if (!stack)
		return (NULL);
	highest = LONG_MIN;
	while (stack)
	{
		if (stack->content > highest)
		{
			highest = stack->content;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	long	lowest;

	if (!stack)
		return (NULL);
	lowest = LONG_MAX;
	while (stack)
	{
		if (stack->content < lowest)
		{
			lowest = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	ft_stack_add_back(t_stack **lst, t_stack *newnode)
{
	t_stack	*current;

	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
}

void	ft_stack_clear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*temp;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}
