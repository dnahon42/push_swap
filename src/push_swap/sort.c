/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:38:20 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/29 18:03:19 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	sort_three(int *a, int sa)
{
	if (sa < 3)
	{
		if (a[0] > a[1])
			ft_sa(a, sa);
		return ;
	}
	if (a[2] < a[0] || a[2] < a[1])
	{
		if (a[0] > a[1] && a[0] > a[2])
			ft_ra(a, sa);
		else if (a[1] > a[0] && a[1] > a[2])
			ft_rra(a, sa);
	}
	if (a[0] > a[1])
		ft_sa(a, sa);
	if (a[1] > a[2])
	{
		ft_ra(a, sa);
		if (a[0] > a[1])
			ft_sa(a, sa);
	}
}

void	sort_four(int *a, int *b, int *sa, int *sb)
{
	int	min;

	min = arr_min(a, *sa);
	if (*sa == 4)
	{
		while (a[0] > min)
			ft_ra(a, *sa);
		ft_pb(a, sa, b, sb);
		sort_three(a, *sa);
		ft_pa(a, sa, b, sb);
	}
}

void	sort_five(int *a, int *b, int *sa, int *sb)
{
	int	min;

	min = arr_min(a, *sa);
	if (*sa == 5)
	{
		while (a[0] > min)
			ft_ra(a, *sa);
		ft_pb(a, sa, b, sb);
		sort_four(a, b, sa, sb);
		ft_pa(a, sa, b, sb);
	}
}

void	sort_small(int *a, int *b, int *sa, int *sb)
{
	if (*sa == 2 || *sa == 3)
		sort_three(a, *sa);
	if (*sa == 4)
		sort_four(a, b, sa, sb);
	if (*sa == 5)
		sort_five(a, b, sa, sb);
}
