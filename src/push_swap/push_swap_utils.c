/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:52:56 by dnahon            #+#    #+#             */
/*   Updated: 2025/06/16 14:22:29 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if ((str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		|| (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	if (size <= 1)
		return (1);
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	max_bit_digit(int *stack, int *size)
{
	int	max;
	int	bits;
	int	i;

	max = stack[0];
	i = 1;
	while (i < *size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	arr_min(int *stack, int size)
{
	int	i;
	int	min;

	i = 1;
	if (size <= 0)
		return (0);
	min = stack[0];
	while (i < size)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min);
}
