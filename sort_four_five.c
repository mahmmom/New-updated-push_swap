#include "push_swap.h"

void	min_of_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	while ((*stack)->content != find_min(*stack)->content)
	{
		if (find_min(*stack)->above_average)
			ra(stack, false);
		else
			rra(stack, false);
	}
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_average = true;
		else
			stack->above_average = false;
		stack = stack->next;
		++i;
	}
}

void	sort_4_5(t_stack **a, t_stack **b)
{
	t_stack	*head;
	int		len_sa;

	head = *a;
	len_sa = ft_stack_size(head);
	current_index(*a);
	min_of_stack(a);
	while (len_sa > 3 && !sorted(*a))
	{
		pb(a, b, false);
		min_of_stack(a);
		len_sa--;
	}
	if (!sorted(*a))
		sort_3(a);
	while (*b)
		pa(a, b, false);
}
