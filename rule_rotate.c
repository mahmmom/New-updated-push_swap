#include "push_swap.h"

static void	rotate(t_stack	**stack)
{
	t_stack *temp;

	if (!stack || !*stack)
		return;
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

void	rr(t_stack	**a, t_stack **b, bool print)
{
	ra(a,false);
	rb(b,false);
	if (!print)
		write(1, "rr\n", 3);
}
