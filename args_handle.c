#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	sign;
	long	result;
	long	i;

	sign = 1;
	result = 0;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i])
		sign = 1 - 2 * (str[i++] == '-');
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = 10 * result + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

char	**parse_args(int arg_count, char **args)
{
	int i;
	char *arg;
	char *tmp;
	char **split;

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
	check_input(split);
	free(arg);
	return (split);
}

static int is_valid_number(char *str)
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

int check_input(char **av)
{
	int i;

    i = 0;
	if (av[0] == NULL)
		error_handle();
	while  (av[i])
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