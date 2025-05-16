/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:55:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/16 16:30:56 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	ft_swap_adjacent(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

/* Print the linked list (assuming int content) */
void	ft_print_list(t_list *head)
{
	while (head)
	{
		ft_printf("%d -> ", *(int *)(head->content));
		head = head->next;
	}
	ft_printf("NULL\n");
}

/* Main function */
int	main(void)
{
	t_list	*head;

	int a, b, c, d, e;
	a = 1, b = 2, c = 3, d = 4, e = 5;
	head = ft_lstnew(&a);
	head->next = ft_lstnew(&b);
	head->next->next = ft_lstnew(&c);
	head->next->next->next = ft_lstnew(&d);
	head->next->next->next->next = ft_lstnew(&e);
	printf("Original list:\n");
	ft_print_list(head);
	ft_swap_adjacent(&head);
	printf("\nList after swapping 2 and 4:\n");
	ft_print_list(head);
	return (0);
}
