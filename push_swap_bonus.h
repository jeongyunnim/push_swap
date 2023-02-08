/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:04 by jeseo             #+#    #+#             */
/*   Updated: 2023/02/08 16:22:03 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024
# define ERROR -1

typedef struct s_deque
{
	struct s_deque	*previous;
	struct s_deque	*next;
	int				num;
}	t_deque;

typedef struct s_deque_edge
{
	struct s_deque	*head_a;
	struct s_deque	*tail_a;
	struct s_deque	*head_b;
	struct s_deque	*tail_b;
}	t_deque_edge;

typedef struct s_pivot_index
{
	int		big_index;
	int		small_index;
	int		middle_index;
	int		pivot_l;
	int		pivot_s;
}	t_pivot_index;

typedef struct s_data
{
	int		*arr;
	char	*arr_data;
	int		num;
}	t_data;

typedef struct s_getline
{
	char	buff[BUFFER_SIZE + 1];
	char	*line;
	int		flag;
}	t_getline;

void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char **s1, char const *s2, size_t len);
void	*ft_memset(void *bytes, int value, size_t len);
int		ft_isnum(char c);
int		ft_isspace(char c);
int		ft_strcmp(const char *str1, const char *str2);

void	free_all(t_data *data, t_deque_edge *edge);
char	*get_next_line(int fd);

t_deque	*lstnew(int num);
t_deque	*pop_head(t_deque **head);
t_deque	*pop_tail(t_deque **tail);
void	append_head(t_deque **head, t_deque **tail, t_deque *new);
void	append_tail(t_deque **head, t_deque **tail, t_deque *new);
void	sa(t_deque_edge *edge);
void	sb(t_deque_edge *edge);
void	ss(t_deque_edge *edge);
void	pa(t_deque_edge *edge);
void	pb(t_deque_edge *edge);
void	ra(t_deque_edge *edge);
void	rb(t_deque_edge *edge);
void	rr(t_deque_edge *edge);
void	rra(t_deque_edge *edge);
void	rrb(t_deque_edge *edge);
void	rrr(t_deque_edge *edge);

void	parsing_argument(t_deque_edge *edge, t_data *data);
void	initialize_structure(t_deque_edge *edge, t_data *data, char **argv);
int		argument_check(char *arg);
void	free_then_exit(t_deque_edge *edge, t_data *data);
int		arranged_check_arr(t_data data);

int		parse_data(t_data *data, char *str);
void	arr_to_deque(t_data *data, t_deque_edge *edge);

#endif