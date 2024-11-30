/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:28:08 by raffi             #+#    #+#             */
/*   Updated: 2023/11/30 10:01:35 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*j;
	unsigned const char	*k;

	j = (unsigned char *)dst;
	k = (unsigned const char *)src;
	i = 0;
	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		j[i] = k[i];
		i++;
	}
	return (j);
}
