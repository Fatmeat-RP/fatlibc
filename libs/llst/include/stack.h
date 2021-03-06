/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:36:01 by acarle-m          #+#    #+#             */
/*   Updated: 2022/04/18 17:13:18 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

/* ************************************************************************** */

# include <stdlib.h>

/* ************************************************************************** */

typedef struct s_llst	t_llst;
typedef struct s_node	t_node;
typedef unsigned long	t_lp64;
typedef unsigned int	t_ui64;
typedef void			(*t_dcons)(void *, void *);
typedef void			(*t_cons)(void *);
typedef struct s_return	t_return;

/* ************************************************************************** */

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE -1
# endif

/* ************************************************************************** */

struct s_node
{
	t_node	*next;
	int		elem;
	size_t	index;
};

struct s_llst
{
	t_node	*first;
};

struct s_return
{
	size_t		r1;
	long		r2;
	void		*r3;
	void		*r4;
	void		*r5;
};

/* ************************************************************************** */

t_llst		*lst_init(void);
t_node		*node_init(t_node *node);
t_node		*ft_lstlast(t_node *node);
t_node		*new_node(int value);
t_node		*new_node_2(int elem, t_node *next);
size_t		ft_lstsize(t_node *node);
void		ft_lstadd_front(t_llst *linked_list, t_node *new);
void		ft_lstadd_back(t_llst *linked_list, t_node *new);
void		node_clear(t_node *node);
void		llst_clear(t_llst *linked_list);
int			lst_not_empty(t_llst *linked_list);
int			lst_is_empty(t_node *node);

int			sa(t_llst *stack_a, int p);
int			pa(t_llst *stack_a, t_llst *stack_b, int p);
int			ra(t_llst *stack_a, int p);
int			rra(t_llst *stack_a, int p);

int			sb(t_llst *stack_b, int p);
int			pb(t_llst *stack_a, t_llst *stack_b, int p);
int			rb(t_llst *stack_b, int p);
int			rrb(t_llst *stack_b, int p);

int			ss(t_llst *stack_a, t_llst *stack_b);
int			rr(t_llst *stack_a, t_llst *stack_b);
int			rrr(t_llst *stack_a, t_llst *stack_b);


#endif
