/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:47:31 by raffi             #+#    #+#             */
/*   Updated: 2023/11/30 10:01:42 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		}
	}
	else if (src >= dst)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
			i++;
		}
	}
	return ((unsigned char *)dst);
}
