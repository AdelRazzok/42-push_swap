/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:40:00 by arazzok           #+#    #+#             */
/*   Updated: 2023/12/15 03:29:27 by arazzok          ###   ########.fr       */
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

// split.c
char					**split(char *s, char c);

// stack_init.c
void					init_stack_a(t_stack_node **a, char **argv,
							bool is_split);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
t_stack_node			*get_cheapest(t_stack_node *stack);

// stack_utils.c
bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);

// sort_three.c
void					sort_three(t_stack_node **a);

// sort_stacks.c
void					sort_stacks(t_stack_node **a, t_stack_node **b);

// init_a_to_b.c
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);

// init_b_to_a.c
void					init_nodes_b(t_stack_node *a, t_stack_node *b);

// error_handler.c
int						error_syntax(char *str);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_split(char **splitted);
int						free_errors(t_stack_node **a, char **splitted,
							bool is_split);

// push.c
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);

// swap.c
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);

// rotate.c
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

// rev_rotate.c
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

#endif
