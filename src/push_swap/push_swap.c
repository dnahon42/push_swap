/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:55:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/16 13:25:35 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int arr[], int low, int high)
{
	int	p;
	int	i;
	int	j;

	p = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= p && i <= high - 1)
		{
			i++;
		}
		while (arr[j] > p && j >= low + 1)
		{
			j--;
		}
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[low], &arr[j]);
	return (j);
}

void	ft_quicksort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		ft_quicksort(arr, low, pi - 1);
		ft_quicksort(arr, pi + 1, high);
	}
}

int	main(int ac, char **av)
{
	int	j;
	int	arr[ac - 1];
	int	n;
	int	i;

	i = 0;
	j = 0;
	while (j < ac - 1)
	{
		if (ft_atoll(av[1 + j]) > INT_MAX || ft_atoll(av[1 + j]) < INT_MIN)
			return (write(2, "Error\n", 6), 0);
		arr[j] = ft_atoi(av[1 + j]);
		j++;
	}
	n = sizeof(arr) / sizeof(arr[0]);
	ft_quicksort(arr, 0, n - 1);
	while (i < n)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	return (0);
}
