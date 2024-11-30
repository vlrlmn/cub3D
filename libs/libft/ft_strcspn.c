/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 23:06:57 by rtchaker          #+#    #+#             */
/*   Updated: 2024/07/02 23:07:20 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*p;
	const char	*r;

	p = s;
	while (*p)
	{
		r = reject;
		while (*r)
		{
			if (*p == *r)
				return (p - s);
			r++;
		}
		p++;
	}
	return (p - s);
}
