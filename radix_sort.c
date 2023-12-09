/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:16:43 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/09 22:24:11 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min_2(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;
	int		flag;

	flag = 0;
	temp = NULL;
	head = *stack;
	while (head != NULL)
	{
		if(head->index == -1 && (flag == 0 || (temp->content > head->content)))
		{
			temp = head;
			flag = 1;
		}
		head = head->next;
	}
	return (temp);
}

/*void	assign_index(t_stack **stack)
{
	t_stack	*head;
	int		i;
	int		j;
	int		index;

	index = 0;
	i = 0;
	head = *stack;
	while(i < ft_stack_size(head))
	{
		j = 0;
		while (j < ft_stack_size(head))
		{
			if (head->index == -1)
			{
				head = find_min_2(stack);
				head->index = index;
				index++;
				printf("Loop min = %d\n", head->content);
			}
			j++;
		}
		i++;
	}
}*/

void assign_index(t_stack **stack)
{
    t_stack	*current;
    int		index;
	
	current = find_min_2(stack);
	index = 0;
	while (current)
    {
		current->index = index++;
        current = find_min_2(stack);
    }
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int max_bits;
	int i;
	int j;
	
	size = ft_stack_size(*stack_a);
	//printf("SIZEE = %d\n", size);
	max_bits = get_max_bits(*stack_a);
	//printf("Maxbits = %d\n", max_bits);
	assign_index(stack_a);
	//print_index(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && !sorted(*stack_a))
		{
			if (*stack_a && (((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b, false);
			else
				ra(stack_a, false);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, false);
		i++;
	}
}
