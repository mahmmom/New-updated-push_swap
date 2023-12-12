#include "push_swap.h"
#include <stdlib.h>

void	print_stack(t_stack	*a)
{
	while ((a) != NULL)
	{
		printf("[%ld]\n", (long)(a)->content);

		(a) = (a)->next;
	}
}
void	print_index(t_stack	*a)
{
	while ((a) != NULL)
	{
		printf("[%ld]\n", (long)(a)->index);

		(a) = (a)->next;
	}
}

static t_stack	*find_last(t_stack	*head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	fill_stack(t_stack **a, int num)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!a)
		return;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return;
	tmp->content = num;
	tmp->index = -1;
	tmp->next = NULL;
	if (!(*a))
	{
		*a = tmp;
		tmp->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = tmp;
		tmp->prev = last_node;
	}
}

void	ft_init_stack(t_stack **a, char **str)
{
	int		i;
	long	num;
	int		flag = 1;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		num = ft_atol(str[i], &flag);
		if (flag == 0)
            return ( free_string(str), ft_stack_clear(a), error_handle());
		if (check_repetition(*a, (int)num))
			return ( free_string(str), ft_stack_clear(a), error_handle());
		fill_stack(a, (int)num);
		i++;
	}
	free_string(str);
}
