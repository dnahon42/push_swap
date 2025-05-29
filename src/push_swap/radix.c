/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:13:38 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/29 15:03:48 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	radix_sort(int *a, int *b, int *sa, int *sb)
{
	int	digits;
	int	i;
	int	bit;
	int	size_a;

	bit = 0;
	digits = max_bit_digit(a, sa);
	while (bit < digits)
	{
		size_a = *sa;
		i = 0;
		while (i < size_a)
		{
			if ((a[0] >> bit & 1) == 0)
				ft_pb(a, sa, b, sb);
			else
				ft_ra(a, *sa);
			i++;
		}
		while (*sb > 0)
			ft_pa(a, sa, b, sb);
		bit++;
	}
}
