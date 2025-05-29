/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:44:21 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/28 15:24:37 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	ft_ra(int *a, int sa)
{
	int	temp;
	int	i;

	if (sa > 1)
	{
		temp = a[0];
		i = 0;
		while (i < sa - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[sa - 1] = temp;
	}
	ft_printf("ra\n");
}

void	ft_rb(int *b, int sb)
{
	int	temp;
	int	i;

	if (sb > 1)
	{
		temp = b[0];
		i = 0;
		while (i < sb - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[sb - 1] = temp;
	}
	ft_printf("rb\n");
}

void	ft_rra(int *a, int sa)
{
	int	temp;
	int	i;

	if (sa > 1)
	{
		temp = a[sa - 1];
		i = sa - 1;
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = temp;
	}
	ft_printf("rra\n");
}

void	ft_rrb(int *b, int sb)
{
	int	temp;
	int	i;

	if (sb > 1)
	{
		temp = b[sb - 1];
		i = sb - 1;
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = temp;
	}
	ft_printf("rrb\n");
}

void	ft_pa(int *a, int *sa, int *b, int *sb)
{
	int	i;

	if (*sb > 0)
	{
		i = *sa;
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = b[0];
		(*sa)++;
		i = 0;
		while (i < (*sb) - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		(*sb)--;
	}
	ft_printf("pa\n");
}
