/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:50:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/01/19 20:57:41 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	// Handle negative numbers
	if (str[i] == '-' || str[i] == '+')
		i++;
	// String must contain at least one digit
	if (!str[i])
	return (0);
	// Check all characters are digits
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	str_to_num(char *str, long *num)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || 
            (sign == -1 && result * sign < INT_MIN))
			return (0);
		i++;
	}
	*num = result * sign;
	return (1);
}  //ATOL

int	parse_args(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	long	num;
	char	**split;
	int		j;

	i = 1;
	while (i < argc)
	{
		if (strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			if (!split)
				return (0);
            j = 0;
            while (split[j])
            {
                if (!is_valid_number(split[j]) || !str_to_num(split[j], &num))
                {
                    free_split(split);
                    return (0);
                }
                if (has_duplicate(stack_a, (int)num))
                {
                    free_split(split);
                    return (0);
                }
                if (!push(stack_a, (int)num))
                {
                    free_split(split);
                    return (0);
                }
                j++;
            }
            free_split(split);
        }
        else
        {
            if (!is_valid_number(argv[i]) || !str_to_num(argv[i], &num))
                return (0);
            if (has_duplicate(stack_a, (int)num))
                return (0);
            if (!push(stack_a, (int)num))
                return (0);
        }
        i++;
    }
    return (1);
}
