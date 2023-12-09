#include "push_swap.h"

static void	swap(t_stack	**stack)
{
	t_stack *temp;

	if (!stack)
		return;
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack	**a, t_stack **b, bool print)
{
	sa(a, print);
	sb(b, print);
	if (!print)
		write(1, "ss\n", 3);
}
