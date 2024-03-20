/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:43:43 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/25 21:55:34 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR_MESSAGE "Error\n"
#define ERROR_ARGS "Error\n"

typedef struct s_stack
{
	int				content;
	int				index;
	bool			above_average;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*
initializing Functions
*/

int					check_input(char **str);
void				start_stack(char **str);
char				**parse_args(int arg_count, char **args);
int					ft_atol(char *str, int *flag);
int					check_repetition(t_stack *a, int nbr);
void				ft_init_stack(t_stack **a, char **str);

/*
RULES
*/

/* swap rules */
void				sa(t_stack **a, bool print);
void				sb(t_stack **b, bool print);
void				ss(t_stack **a, t_stack **b, bool print);

/* push rules */
void				pa(t_stack **a, t_stack **b, bool print);
void				pb(t_stack **a, t_stack **b, bool print);

/* rotate */
void				ra(t_stack **a, bool print);
void				rb(t_stack **b, bool print);
void				rr(t_stack **a, t_stack **b, bool print);

/*  rrotate */
void				rra(t_stack **a, bool print);
void				rrb(t_stack **b, bool print);
void				rrr(t_stack **a, t_stack **b, bool print);

/*
Sorting Algorthim
*/

/* small numbers */
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_2_3(t_stack **stack);
void				sort_4_5(t_stack **a, t_stack **b);
bool				sorted(t_stack *a);

/* Radix Algorithm */
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
void				assign_index(t_stack **stack);
int					get_max_bits(t_stack *stack);
t_stack				*find_min_2(t_stack **stack);

/*
Helping Functions
*/

/* stack utils  */
t_stack				*ft_stack_new(int content);
void				ft_stack_add_back(t_stack **lst, t_stack *newnode);
int					ft_stack_size(t_stack *lst);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);
void				ft_stack_clear(t_stack **lst);

/* Error Handle */
void				free_string(char **str);
void				putstr_fd(char *s, int fd);
void				error_handle(void);