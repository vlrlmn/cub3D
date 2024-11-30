/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:34:49 by raffi             #+#    #+#             */
/*   Updated: 2023/11/30 10:01:50 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*x;

	x = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		x[i] = (unsigned char )c;
		i++;
	}
	return (b);
}
