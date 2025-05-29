/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:31:20 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/29 14:47:43 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	ft_pb(int *a, int *sa, int *b, int *sb)
{
	int	i;

	if (*sa > 0)
	{
		i = *sb;
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = a[0];
		(*sb)++;
		i = 0;
		while (i < (*sa) - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		(*sa)--;
	}
	ft_printf("pb\n");
}

void	ft_sa(int *a, int sa)
{
	int	temp;

	if (sa > 1)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	ft_printf("sa\n");
}

void	ft_sb(int b[], int sb)
{
	int	temp;

	if (sb > 1)
	{
		temp = b[0];
		b[0] = b[1];
		b[1] = temp;
	}
	ft_printf("sb\n");
}
