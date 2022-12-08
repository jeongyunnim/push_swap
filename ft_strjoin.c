/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:42:08 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/08 20:23:02 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			i;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (c_dest == src || len == 0)
		return (dest);
	if (dest <= src)
	{
		i = -1;
		while (++i < len)
			c_dest[i] = c_src[i];
	}
	else
	{
		while (len > 0)
		{
			c_dest[len - 1] = c_src[len - 1];
			len--;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (res == 0)
		return (NULL);
	ft_memmove(res, s1, s1_len);
	ft_memmove(res + s1_len, s2, s2_len);
	return (res);
}
