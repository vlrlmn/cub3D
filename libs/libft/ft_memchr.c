/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:32:28 by raffi             #+#    #+#             */
/*   Updated: 2023/11/30 10:01:23 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*x;
	unsigned char	c_c;

	x = (unsigned char *)s;
	c_c = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (c_c == *x)
		{
			return (x);
		}
		x++;
		i++;
	}
	return (NULL);
}
