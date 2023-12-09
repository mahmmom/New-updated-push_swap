/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:25:50 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/09 22:08:03 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_stack *stack)
{
    int max_bits;
	int num_bits;
	int num;

    max_bits = 0;
	while (stack)
    {
        num_bits = 0;
        num = stack->content;
		if (num < 0)
			num *= -1;
        while (num > 0)
        {
            num >>= 1;
            num_bits++;
        }
        if (num_bits > max_bits)
            max_bits = num_bits;
        stack = stack->next;
    }
    return (max_bits);
}
