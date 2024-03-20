/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:43:25 by mohamoha          #+#    #+#             */
/*   Updated: 2023/12/12 21:11:55 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *str, int *flag)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
	{
		*flag = 0;
		return (0);
	}
	return (number * sign);
}

char	**parse_args(int arg_count, char **args)
{
	int		i;
	char	*arg;
	char	*tmp;
	char	**split;

	if (!arg_count || !args)
		ft_putstr_fd(ERROR_ARGS, 2);
	i = 1;
	arg = ft_strjoin(args[i++], " ");
	while (args[i])
	{
		tmp = ft_strjoin(arg, args[i]);
		free(arg);
		arg = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	split = ft_split(arg, ' ');
	free(arg);
	check_input(split);
	return (split);
}

static int	is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	check_input(char **av)
{
	int	i;

	i = 0;
	if (av[0] == NULL)
		error_handle();
	while (av[i])
	{
		if (is_valid_number(av[i]))
		{
			free_string(av);
			error_handle();
		}
		i++;
	}
	return (1);
}

int	check_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
