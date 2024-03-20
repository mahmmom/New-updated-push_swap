/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:42:54 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/20 18:17:39 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *a, t_stack *b)
{
	if (a)
		ft_stack_clear(&a);
	if (b)
		ft_stack_clear(&b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (1 == ac)
		return (0);
	if (2 == ac && !av[1][0])
		error_handle();
	a = NULL;
	b = NULL;
	av = parse_args(ac - 1, av);
	ft_init_stack(&a, av);
	if (!sorted(a))
	{
		if (ft_stack_size(a) == 2 || ft_stack_size(a) == 3)
			sort_2_3(&a);
		else if (ft_stack_size(a) == 4 || ft_stack_size(a) == 5)
			sort_4_5(&a, &b);
		else
			radix_sort(&a, &b);
	}
	free_stack(a, b);
	return (0);
}
