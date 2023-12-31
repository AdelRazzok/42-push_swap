/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:52:18 by arazzok           #+#    #+#             */
/*   Updated: 2023/12/15 03:32:24 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (1);
	if ((*str == '+' || *str == '-') && !ft_isdigit(str[1]))
		return (1);
	while (*++str)
	{
		if (!ft_isdigit(*str))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_split(char **splitted)
{
	int	i;

	if (!splitted)
		return ;
	i = -1;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted - 1);
}

int	free_errors(t_stack_node **a, char **splitted, bool is_split)
{
	free_stack(a);
	if (is_split)
		free_split(splitted);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (1);
}
