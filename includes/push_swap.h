/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:10:17 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/29 18:11:53 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Instructions

void	ft_ra(int *stack_a, int size_a);
void	ft_rb(int *stack_b, int size_b);
void	ft_rra(int *stack_a, int size_a);
void	ft_rrb(int *stack_b, int size_b);
void	ft_pa(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	ft_pb(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	ft_sa(int *stack_a, int size_a);
void	ft_sb(int *stack_b, int size_b);

// Parsing

int		parse_split_arguments(char *arg, int **stack_a);
int		parse_direct_arguments(int argc, char **argv, int **stack_a);
int		parse_arguments(int argc, char **argv, int **stack_a);
int		checkdup_onearg(int argc, char **argv, int **a);
int		check_duplicates(int size, char **array);

// Sorting

void	radix_sort(int *a, int *b, int *sa, int *sb);
void	sort_three(int *stack_a, int size_a);
void	sort_four(int *a, int *b, int *sa, int *sb);
void	sort_five(int *a, int *b, int *sa, int *sb);
void	sort_small(int *a, int *b, int *sa, int *sb);

// Others

void	ft_error(void);
int		is_valid_number(char *str);
int		max_bit_digit(int *stack, int *size);
int		arr_min(int *stack, int size);
int		is_sorted(int *stack, int size);
void	simplify_to_index(int *arr, int size);
void	ft_free_split(char **split);
void	*free_all(char **tab, int j);

#endif
