/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:40:00 by arazzok           #+#    #+#             */
/*   Updated: 2023/12/11 12:50:38 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapset;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// stack_init.c
void	init_stack_a(t_stack_node **a, char **argv);

// stack_utils.c
bool	stack_sorted(t_stack_node *stack);

// sort_three.c
void	sort_three(t_stack_node **a);

// sort_stacks.c
void	sort_stacks(t_stack_node **a, t_stack_node **b);

// init_a_to_b.c
void	current_index(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);

#endif
