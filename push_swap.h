/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:04 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/23 22:03:07 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*previous;
	struct s_list	*next;
	int				num;
}	t_list;

typedef struct	s_list_edge
{
	struct s_list	*head_a;
	struct s_list	*tail_a;
	struct s_list	*head_b;
	struct s_list	*tail_b;
}	t_list_edge;

typedef struct	s_data
{
	int	*arr;
	int	num;
}	t_data;

#endif