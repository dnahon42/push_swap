/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:30:28 by dnahon            #+#    #+#             */
/*   Updated: 2025/06/06 14:19:49 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

int	parse_split_arguments(char *arg, int **a)
{
	char	**splitted;
	int		count;
	int		i;

	splitted = ft_split(arg, ' ');
	if (!splitted)
		return (-1);
	count = 0;
	while (splitted[count])
		count++;
	if (count == 0)
		return (ft_free_split(splitted), ft_error(), -1);
	*a = ft_malloc(count * sizeof(int));
	if (!*a)
		return (ft_free_split(splitted), ft_error(), -1);
	i = 0;
	while (i < count)
	{
		if (!is_valid_number(splitted[i]))
			return (ft_free_split(splitted), ft_error(), -1);
		(*a)[i] = ft_atoi(splitted[i]);
		i++;
	}
	return (ft_free_split(splitted), count);
}

int	parse_direct_arguments(int argc, char **argv, int **a)
{
	int	sa;
	int	i;

	sa = 0;
	i = 1;
	*a = ft_malloc((argc - 1) * sizeof(int));
	if (!*a)
		return (-1);
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (ft_free(*a), ft_error(), -1);
		else if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
			ft_error();
		(*a)[sa++] = ft_atoi(argv[i++]);
	}
	return (sa);
}

int	check_duplicates(int size, char **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				return (ft_error(), -1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checkdup_onearg(int argc, char **argv, int **a)
{
	char	**splitted;
	int		size;
	int		i;

	if (argc != 2 || !argv[1] || !*argv[1])
		return (ft_error(), -1);
	splitted = ft_split(argv[1], ' ');
	if (!splitted)
		return (-1);
	i = 0;
	while (splitted[i])
	{
		if (ft_atoll(splitted[i]) > INT_MAX || ft_atoll(splitted[i]) < INT_MIN)
			return (free_all(splitted, i), ft_error(), -1);
		i++;
	}
	size = i;
	if (size == 0 || check_duplicates(size, splitted) == -1)
		return (free_all(splitted, size - 1), ft_error(), -1);
	free_all(splitted, size - 1);
	return (parse_split_arguments(argv[1], a));
}

int	parse_arguments(int argc, char **argv, int **a)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
		return (checkdup_onearg(argc, argv, a));
	else
		return (check_duplicates(argc, argv), parse_direct_arguments(argc, argv,
				a));
}
