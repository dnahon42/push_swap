/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:55:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/29 17:01:49 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	simplify_to_index(int *arr, int size)
{
	int	*new_arr;
	int	i;
	int	j;
	int	k;

	i = -1;
	if (size <= 0)
		return ;
	new_arr = (int *)ft_malloc(size * sizeof(int));
	if (!new_arr)
		ft_error();
	while (++i < size)
	{
		k = 0;
		j = -1;
		while (++j < size)
			if (arr[i] > arr[j])
				k++;
		new_arr[i] = k;
	}
	i = -1;
	while (++i < size)
		arr[i] = new_arr[i];
	ft_free(new_arr);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	sa;
	int	sb;

	a = NULL;
	b = NULL;
	sb = 0;
	if (argc < 2)
		return (0);
	sa = parse_arguments(argc, argv, &a);
	if (sa <= 0)
		return (ft_free(a), 1);
	b = (int *)ft_malloc(sa * sizeof(int));
	if (!b)
		return (ft_free(a), 1);
	if (is_sorted(a, sa))
		return (ft_free(a), ft_free(b), 0);
	if (sa >= 2 && sa <= 5)
		sort_small(a, b, &sa, &sb);
	else if (sa > 5)
		radix_sort(a, b, &sa, &sb);
	return (ft_free(a), ft_free(b), 0);
}
