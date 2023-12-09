#include "libft/libft.h"
#include "push_swap.h"

void	del(t_list *lst)
{
	free(lst);
}

void	free_stack(t_stack *a, t_stack *b)
{
	if (a)
		ft_stack_clear(&a);
	if (b)
		ft_stack_clear(&b);
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (1 == ac || (2 == ac && !av[1][0]))
		exit(EXIT_FAILURE);
	a = NULL;
	b = NULL;
	av = parse_args(ac-1, av);
	ft_init_stack(&a,av);
	if (!sorted(a))
	{
		if (ft_stack_size(a) == 2 || ft_stack_size(a) == 3)
			sort_2_3(&a);
		else if (ft_stack_size(a) == 4 || ft_stack_size(a) == 5)
			sort_4_5(&a, &b);
		else
			radix_sort(&a, &b);
	}
	//print_stack(a);
	free_stack(a,b);
	return (0);
}
